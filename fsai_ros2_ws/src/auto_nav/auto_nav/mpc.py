#!/usr/bin/env python3
"""
Kinematic MPC Lateral Controller
==================================
Model Predictive Control for path tracking using a kinematic bicycle model.
All path data (heading, curvature, speed profile) is derived internally from
the raw /map/path positions — no changes to array_map required.

State  : [e_cte, e_psi]   cross-track error, heading error
Control: [delta]           steering angle
Horizon: N steps at dt seconds

Speed is planned separately using preview curvature (same approach as stanley).
Solved with scipy L-BFGS-B, warm-started from the shifted previous solution.

Usage:
    ros2 run auto_nav mpc
    ros2 run auto_nav mpc --ros-args -p N:=12 -p lat_accel_limit:=10.0
"""

import rclpy
from rclpy.node import Node
import math
import numpy as np
from scipy.optimize import minimize

from nav_msgs.msg import Path, Odometry
from visualization_msgs.msg import Marker, MarkerArray
from vehiclecontrol_msgs.msg import VehicleControl


class MPCController(Node):
    def __init__(self):
        super().__init__('mpc_controller')

        # MPC horizon
        self.declare_parameter('N',                  10)     # prediction steps
        self.declare_parameter('dt',                  0.1)   # seconds per step

        # Cost weights
        self.declare_parameter('w_cte',              2.0)    # cross-track error
        self.declare_parameter('w_psi',              1.0)    # heading error
        self.declare_parameter('w_steer',            0.1)    # steering magnitude
        self.declare_parameter('w_dsteer',           0.5)    # steering rate

        # Speed planning
        self.declare_parameter('v_max',              8.0)    # m/s
        self.declare_parameter('v_min',              1.0)    # m/s
        self.declare_parameter('lat_accel_limit',    8.0)    # m/s²
        self.declare_parameter('preview_distance',  15.0)    # m

        # Vehicle / limits
        self.declare_parameter('max_steering',       0.6)    # rad
        self.declare_parameter('wheelbase',          1.53)   # m
        self.declare_parameter('max_gas',            0.4)
        self.declare_parameter('min_gas',            0.1)

        def gp(n):   return self.get_parameter(n).get_parameter_value().double_value
        def gi(n):   return self.get_parameter(n).get_parameter_value().integer_value

        self.N                 = gi('N')
        self.dt                = gp('dt')
        self.w_cte             = gp('w_cte')
        self.w_psi             = gp('w_psi')
        self.w_steer           = gp('w_steer')
        self.w_dsteer          = gp('w_dsteer')
        self.v_max             = gp('v_max')
        self.v_min             = gp('v_min')
        self.lat_accel_limit   = gp('lat_accel_limit')
        self.preview_distance  = gp('preview_distance')
        self.max_steering      = gp('max_steering')
        self.wheelbase         = gp('wheelbase')
        self.max_gas           = gp('max_gas')
        self.min_gas           = gp('min_gas')

        # Path data — computed once when path arrives.
        self.path_pts         = None   # (N_path, 2)
        self.path_yaws        = None   # (N_path,)  tangent heading at each point
        self.path_curvatures  = None   # (N_path,)
        self.path_v_ref       = None   # (N_path,)  target speed at each point

        self.car_x     = 0.0
        self.car_y     = 0.0
        self.car_yaw   = 0.0
        self.car_speed = 0.0

        # Warm-start: previous optimised steering sequence.
        self.u_prev = np.zeros(self.N)
        self.prev_steering = 0.0

        self.create_subscription(Path,     '/map/path',      self._path_cb, 10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb, 10)

        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.viz_pub = self.create_publisher(MarkerArray,    '/mpc/debug',               10)

        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'MPC controller started — N={self.N} dt={self.dt}s '
            f'horizon={self.N*self.dt:.1f}s  '
            f'weights: cte={self.w_cte} psi={self.w_psi} '
            f'steer={self.w_steer} dsteer={self.w_dsteer}'
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

        # Tangent heading at each point (use next point; wrap at end).
        yaws = np.empty(n)
        for k in range(n):
            nxt   = (k + 1) % n
            delta = pts[nxt] - pts[k]
            yaws[k] = math.atan2(delta[1], delta[0])

        # Menger curvature at each point.
        kappas = np.zeros(n)
        for k in range(n):
            p  = pts[(k - 1) % n]
            c  = pts[k]
            nx = pts[(k + 1) % n]
            v1, v2 = c - p, nx - c
            l1, l2 = np.linalg.norm(v1), np.linalg.norm(v2)
            if l1 > 0 and l2 > 0:
                cross      = abs(v1[0] * v2[1] - v1[1] * v2[0])
                kappas[k]  = cross / (l1 * l2 * (l1 + l2) / 2.0 + 1e-9)

        # Speed profile: v_safe = sqrt(a_lat / kappa), clipped to [v_min, v_max].
        v_ref = np.where(
            kappas > 1e-4,
            np.sqrt(self.lat_accel_limit / np.maximum(kappas, 1e-4)),
            self.v_max,
        )
        v_ref = np.clip(v_ref, self.v_min, self.v_max)

        self.path_pts        = pts
        self.path_yaws       = yaws
        self.path_curvatures = kappas
        self.path_v_ref      = v_ref

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

    # ── MPC helpers ──────────────────────────────────────────────────────────

    def _nearest_idx(self):
        car = np.array([self.car_x, self.car_y])
        return int(np.argmin(np.linalg.norm(self.path_pts - car, axis=1)))

    def _initial_errors(self, nearest):
        pts  = self.path_pts
        tx   = math.cos(self.path_yaws[nearest])
        ty   = math.sin(self.path_yaws[nearest])
        dx   = self.car_x - pts[nearest, 0]
        dy   = self.car_y - pts[nearest, 1]
        e_cte = -(tx * dy - ty * dx)           # same sign convention as Stanley
        e_psi  = self.path_yaws[nearest] - self.car_yaw
        e_psi  = math.atan2(math.sin(e_psi), math.cos(e_psi))
        return e_cte, e_psi

    def _max_curvature_ahead(self, start_idx):
        pts    = self.path_pts
        n      = len(pts)
        accum  = 0.0
        idx    = start_idx
        kmax   = 0.0
        while accum < self.preview_distance:
            kmax  = max(kmax, self.path_curvatures[idx])
            nxt   = (idx + 1) % n
            accum += np.linalg.norm(pts[nxt] - pts[idx])
            idx   = nxt
            if idx == start_idx:
                break
        return kmax

    def _solve(self, e_cte0, e_psi0, v, nearest):
        N   = self.N
        dt  = self.dt
        L   = self.wheelbase
        n_path = len(self.path_pts)

        # Gather curvatures along the predicted horizon.
        kappas = np.array([
            self.path_curvatures[(nearest + k) % n_path]
            for k in range(N)
        ])

        w_cte    = self.w_cte
        w_psi    = self.w_psi
        w_steer  = self.w_steer
        w_dsteer = self.w_dsteer
        v_eff    = max(v, 0.5)    # avoid near-zero speed in dynamics

        def cost(u):
            e_c  = e_cte0
            e_p  = e_psi0
            prev = self.prev_steering
            total = 0.0
            for k in range(N):
                delta = u[k]
                total += w_cte    * e_c ** 2
                total += w_psi    * e_p ** 2
                total += w_steer  * delta ** 2
                total += w_dsteer * (delta - prev) ** 2
                # Kinematic bicycle error dynamics.
                e_c  += v_eff * math.sin(e_p) * dt
                e_p  += (v_eff / L * math.tan(delta) - kappas[k] * v_eff) * dt
                prev  = delta
            return total

        # Warm start: shift previous solution, pad with zero.
        u0         = np.empty(N)
        u0[:-1]    = self.u_prev[1:]
        u0[-1]     = 0.0

        bounds = [(-self.max_steering, self.max_steering)] * N

        result = minimize(
            cost, u0,
            method  = 'L-BFGS-B',
            bounds  = bounds,
            options = {'maxiter': 20, 'ftol': 1e-5},
        )
        self.u_prev = result.x
        return float(result.x[0])

    # ── Control loop ─────────────────────────────────────────────────────────

    def _control_loop(self):
        if self.path_pts is None:
            return

        nearest          = self._nearest_idx()
        e_cte, e_psi     = self._initial_errors(nearest)
        steering         = self._solve(e_cte, e_psi, self.car_speed, nearest)
        self.prev_steering = steering

        # Speed planning (preview curvature, same as Stanley / adaptive_pursuit).
        kappa_max = self._max_curvature_ahead(nearest)
        if kappa_max > 1e-4:
            v_target = math.sqrt(self.lat_accel_limit / kappa_max)
        else:
            v_target = self.v_max

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
        cmd.steer_ang     = float(np.clip(steering, -self.max_steering, self.max_steering))
        self.cmd_pub.publish(cmd)

        self._publish_debug(nearest)

        if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:
            self.get_logger().info(
                f'e_cte={e_cte:.3f}m  e_psi={math.degrees(e_psi):.1f}°  '
                f'δ={math.degrees(steering):.1f}°  '
                f'spd={self.car_speed:.1f}  v_tgt={v_target:.1f}  '
                f'gas={gas:.2f}  brake={brake:.2f}'
            )

    def _publish_debug(self, nearest):
        stamp = self.get_clock().now().to_msg()
        ma    = MarkerArray()

        # Predicted horizon points.
        pts   = self.path_pts
        n     = len(pts)
        for k in range(self.N):
            idx = (nearest + k) % n
            m   = Marker()
            m.header.frame_id    = 'Obj_F'
            m.header.stamp       = stamp
            m.ns, m.id           = 'mpc_horizon', k
            m.type               = Marker.SPHERE
            m.action             = Marker.ADD
            m.pose.position.x    = float(pts[idx, 0])
            m.pose.position.y    = float(pts[idx, 1])
            m.pose.orientation.w = 1.0
            t = k / max(self.N - 1, 1)
            m.scale.x = m.scale.y = m.scale.z = 0.2
            m.color.r = t
            m.color.b = 1.0 - t
            m.color.a = 0.8
            m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
            ma.markers.append(m)

        self.viz_pub.publish(ma)


def main(args=None):
    rclpy.init(args=args)
    node = MPCController()
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
