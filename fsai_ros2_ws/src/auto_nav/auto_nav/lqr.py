#!/usr/bin/env python3
"""
LTV-LQR Path Tracking Controller
===================================
Linear Quadratic Regulator for path tracking using the linearised kinematic
bicycle model. "LTV" (Linear Time-Varying) means the gain matrix K is
recomputed for each path point using the local reference speed, so the
controller stays optimal across the full speed range.

Error-state dynamics (linearised around reference path):
    e_cte[k+1] = e_cte[k] + v·dt · e_psi[k]
    e_psi[k+1] = e_psi[k] + v·dt/L · delta[k]  -  kappa·v·dt

    A = [[1,  v·dt ],    B = [[   0    ],    d = [       0      ]
         [0,   1   ]]        [v·dt / L ]]        [-kappa·v·dt   ]

LQR finds gain K (via DARE) minimising  Σ xᵀQx + uᵀRu
Steering:  delta = delta_ff  -  K · [e_cte, e_psi]ᵀ
           where delta_ff = arctan(kappa · L)  (feedforward for curvature)

Gains are solved once per path point when the map arrives (cached by speed),
so the control loop is a single matrix multiply — no online optimisation.

Speed uses the same global two-pass profile as the Stanley node.

Usage:
    ros2 run auto_nav lqr
    ros2 run auto_nav lqr --ros-args -p q_cte:=2.0 -p q_psi:=1.0 -p r_steer:=0.05
"""

import rclpy
from rclpy.node import Node
import math
import numpy as np
from scipy.linalg import solve_discrete_are

from nav_msgs.msg import Path, Odometry
from visualization_msgs.msg import Marker, MarkerArray
from vehiclecontrol_msgs.msg import VehicleControl


class LQRController(Node):
    def __init__(self):
        super().__init__('lqr_controller')

        # LQR cost weights.
        self.declare_parameter('q_cte',             1.0)   # cross-track error cost
        self.declare_parameter('q_psi',             1.0)   # heading error cost
        self.declare_parameter('r_steer',           0.1)   # steering effort cost

        # Discretisation timestep for model (matches control rate).
        self.declare_parameter('dt',                0.02)  # s

        # Speed profile.
        self.declare_parameter('v_max',             8.0)   # m/s
        self.declare_parameter('v_min',             1.5)   # m/s
        self.declare_parameter('a_accel',           4.0)   # m/s²
        self.declare_parameter('a_brake',           8.0)   # m/s²
        self.declare_parameter('lat_accel_limit',   8.0)   # m/s²

        # Vehicle / control limits.
        self.declare_parameter('wheelbase',         1.53)  # m
        self.declare_parameter('max_steering',      0.6)   # rad
        self.declare_parameter('steering_alpha',    0.2)   # smoothing
        self.declare_parameter('max_gas',           0.6)
        self.declare_parameter('min_gas',           0.1)

        def gp(n): return self.get_parameter(n).get_parameter_value().double_value

        self.q_cte           = gp('q_cte')
        self.q_psi           = gp('q_psi')
        self.r_steer         = gp('r_steer')
        self.dt              = gp('dt')
        self.v_max           = gp('v_max')
        self.v_min           = gp('v_min')
        self.a_accel         = gp('a_accel')
        self.a_brake         = gp('a_brake')
        self.lat_accel_limit = gp('lat_accel_limit')
        self.wheelbase       = gp('wheelbase')
        self.max_steering    = gp('max_steering')
        self.steering_alpha  = gp('steering_alpha')
        self.max_gas         = gp('max_gas')
        self.min_gas         = gp('min_gas')

        self.Q = np.diag([self.q_cte, self.q_psi])
        self.R = np.array([[self.r_steer]])

        # Path data — populated once when /map/path arrives.
        self.path_pts  = None   # (N, 2)
        self.path_yaws = None   # (N,)   tangent heading at each point
        self.kappas    = None   # (N,)   Menger curvature
        self.v_profile = None   # (N,)   target speed from two-pass planner
        self.gains     = None   # (N,)   LQR gain K[k] shape (1, 2) per point

        self.car_x         = 0.0
        self.car_y         = 0.0
        self.car_yaw       = 0.0
        self.car_speed     = 0.0
        self.prev_steering = 0.0
        self._nearest_idx  = 0      # monotonically advanced, never jumps back

        self.create_subscription(Path,     '/map/path',      self._path_cb, 10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb, 10)

        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.viz_pub = self.create_publisher(MarkerArray,    '/lqr/debug',               10)

        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'LQR controller started — '
            f'Q=[{self.q_cte},{self.q_psi}]  R=[{self.r_steer}]  dt={self.dt}s'
        )

    # ── Path preprocessing ────────────────────────────────────────────────────

    def _path_cb(self, msg):
        if len(msg.poses) < 3:
            return

        pts = np.array(
            [(p.pose.position.x, p.pose.position.y) for p in msg.poses],
            dtype=float,
        )
        n = len(pts)

        # Tangent headings via central difference — smoother than forward-only
        # because it averages out per-point lateral noise in cone midpoints.
        yaws = np.array([
            math.atan2(*(pts[(k + 1) % n] - pts[(k - 1) % n])[::-1])
            for k in range(n)
        ])

        # Menger curvatures.
        kappas = np.zeros(n)
        for k in range(n):
            v1 = pts[k]           - pts[(k - 1) % n]
            v2 = pts[(k + 1) % n] - pts[k]
            l1, l2 = np.linalg.norm(v1), np.linalg.norm(v2)
            if l1 > 0 and l2 > 0:
                cross     = abs(v1[0] * v2[1] - v1[1] * v2[0])
                kappas[k] = cross / (l1 * l2 * (l1 + l2) / 2.0 + 1e-9)

        v_profile = self._two_pass_profile(pts, kappas)
        gains     = self._compute_gains(v_profile)

        self.path_pts      = pts
        self.path_yaws     = yaws
        self.kappas        = kappas
        self.v_profile     = v_profile
        self.gains         = gains
        self._nearest_idx  = 0

        self.get_logger().info(
            f'Path ready — {n} points  '
            f'v: {v_profile.min():.1f}–{v_profile.max():.1f} m/s  '
            f'mean {v_profile.mean():.1f} m/s'
        )

    def _two_pass_profile(self, pts, kappas):
        n  = len(pts)
        ds = np.array([np.linalg.norm(pts[(k + 1) % n] - pts[k]) for k in range(n)])

        v_lat = np.where(kappas > 1e-4,
                         np.sqrt(self.lat_accel_limit / np.maximum(kappas, 1e-4)),
                         self.v_max)
        v = np.clip(v_lat, self.v_min, self.v_max)

        for _ in range(2):                          # forward pass ×2
            for k in range(n):
                nxt    = (k + 1) % n
                v[nxt] = min(v[nxt], math.sqrt(v[k] ** 2 + 2 * self.a_accel * ds[k]))

        for _ in range(2):                          # backward pass ×2
            for k in range(n - 1, -1, -1):
                prv    = (k - 1) % n
                v[prv] = min(v[prv], math.sqrt(v[k] ** 2 + 2 * self.a_brake * ds[prv]))

        return np.clip(v, self.v_min, self.v_max)

    def _compute_gains(self, v_profile):
        """Solve DARE for each unique reference speed; cache results."""
        cache = {}
        gains = []
        for v_ref in v_profile:
            key = round(float(v_ref), 2)
            if key not in cache:
                A = np.array([[1.0, v_ref * self.dt],
                              [0.0, 1.0            ]])
                B = np.array([[0.0                 ],
                              [v_ref * self.dt / self.wheelbase]])
                try:
                    P      = solve_discrete_are(A, B, self.Q, self.R)
                    K      = np.linalg.inv(self.R + B.T @ P @ B) @ B.T @ P @ A
                except Exception:
                    K      = np.array([[0.0, 1.0]])   # fallback: heading-only
                cache[key] = K
            gains.append(cache[key])

        self.get_logger().info(f'LQR gains computed ({len(cache)} unique speeds)')
        return gains

    # ── Odom ─────────────────────────────────────────────────────────────────

    def _odom_cb(self, msg):
        self.car_x   = msg.pose.pose.position.x
        self.car_y   = msg.pose.pose.position.y
        q            = msg.pose.pose.orientation
        self.car_yaw = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )
        self.car_speed = math.sqrt(
            msg.twist.twist.linear.x ** 2 +
            msg.twist.twist.linear.y ** 2
        )

    # ── Control loop ─────────────────────────────────────────────────────────

    def _control_loop(self):
        if self.path_pts is None:
            return

        pts = self.path_pts
        n   = len(pts)
        car = np.array([self.car_x, self.car_y])

        # Search only within a window ahead of the last known nearest point.
        # This prevents the index from jumping backwards when two adjacent
        # points are equidistant, which would cause heading-error oscillation.
        window  = 10
        indices = [(self._nearest_idx + i) % n for i in range(window)]
        local   = int(np.argmin(np.linalg.norm(pts[indices] - car, axis=1)))
        self._nearest_idx = indices[local]
        nearest = self._nearest_idx

        # Path tangent at nearest point.
        tx = math.cos(self.path_yaws[nearest])
        ty = math.sin(self.path_yaws[nearest])

        # Cross-track error: positive = car right of path = steer left.
        dx    = self.car_x - pts[nearest, 0]
        dy    = self.car_y - pts[nearest, 1]
        e_cte = -(tx * dy - ty * dx)

        # Heading error: wrap to (−π, π).
        e_psi = self.path_yaws[nearest] - self.car_yaw
        e_psi = math.atan2(math.sin(e_psi), math.cos(e_psi))

        # LQR feedback.
        K        = self.gains[nearest]
        x_err    = np.array([[e_cte], [e_psi]])
        delta_fb = float(-(K @ x_err)[0, 0])

        # Feedforward: steering needed to follow path curvature with no error.
        kappa      = self.kappas[nearest]
        delta_ff   = math.atan(kappa * self.wheelbase)

        steering = delta_ff + delta_fb
        steering = (self.steering_alpha * steering +
                   (1.0 - self.steering_alpha) * self.prev_steering)
        steering = float(np.clip(steering, -self.max_steering, self.max_steering))
        self.prev_steering = steering

        # Speed from global profile.
        v_target = float(self.v_profile[nearest])
        if self.car_speed > v_target:
            gas   = 0.0
            brake = float(np.clip((self.car_speed - v_target) / max(v_target, 0.1), 0.0, 1.0))
        else:
            headroom = min(v_target - self.car_speed, 2.0) / 2.0
            gas      = float(np.clip(
                self.min_gas + (self.max_gas - self.min_gas) * headroom,
                self.min_gas, self.max_gas,
            ))
            brake = 0.0

        cmd               = VehicleControl()
        cmd.use_vc        = True
        cmd.selector_ctrl = 1
        cmd.gas           = gas
        cmd.brake         = brake
        cmd.steer_ang     = steering
        self.cmd_pub.publish(cmd)

        self._publish_debug(pts[nearest], e_cte)

        if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:
            self.get_logger().info(
                f'e_cte={e_cte:.3f}m  e_psi={math.degrees(e_psi):.1f}°  '
                f'δ_ff={math.degrees(delta_ff):.1f}°  '
                f'δ_fb={math.degrees(delta_fb):.1f}°  '
                f'δ={math.degrees(steering):.1f}°  '
                f'spd={self.car_speed:.1f}  v_tgt={v_target:.1f}  '
                f'gas={gas:.2f}  brake={brake:.2f}'
            )

    # ── Debug visualisation ───────────────────────────────────────────────────

    def _publish_debug(self, nearest_pt, cte):
        stamp = self.get_clock().now().to_msg()
        ma    = MarkerArray()

        m = Marker()
        m.header.frame_id    = 'Obj_F'
        m.header.stamp       = stamp
        m.ns, m.id           = 'lqr', 0
        m.type               = Marker.SPHERE
        m.action             = Marker.ADD
        m.pose.position.x    = float(nearest_pt[0])
        m.pose.position.y    = float(nearest_pt[1])
        m.pose.orientation.w = 1.0
        m.scale.x = m.scale.y = m.scale.z = 0.4
        m.color.r = float(min(abs(cte), 1.0))
        m.color.g = float(1.0 - min(abs(cte), 1.0))
        m.color.a = 1.0
        m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        ma.markers.append(m)

        self.viz_pub.publish(ma)


def main(args=None):
    rclpy.init(args=args)
    node = LQRController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        stop               = VehicleControl()
        stop.use_vc        = True
        stop.selector_ctrl = 1
        stop.brake         = 1.0
        node.cmd_pub.publish(stop)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
