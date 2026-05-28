#!/usr/bin/env python3
"""
iLQR Path Tracking Controller
================================
Iterative Linear Quadratic Regulator for path tracking.

LQR linearises the bicycle model once around the reference path (e=0).
iLQR improves on this by iteratively re-linearising around the *actual*
predicted trajectory, so the gains stay accurate even when the car is
significantly off the path.

Algorithm (runs n_iter times per control tick):

  Forward pass  — roll out nonlinear error dynamics with current controls
                  to get the nominal trajectory Ē = [ē_0 … ē_N].

  Backward pass — linearise dynamics at each Ē_k, compute Riccati
                  recursion to get per-step feedforward k_k and
                  feedback K_k gains.

  Update        — apply α·k_k + K_k·(ẽ_k − ē_k) to improve controls.

Error state:  x = [e_cte, e_psi]
Control:      u = [δ]            (steering angle)

Nonlinear error dynamics:
    e_cte[k+1] = e_cte[k] + v·sin(e_psi[k])·dt
    e_psi[k+1] = e_psi[k] + v/L·tan(δ[k])·dt  −  κ_k·v·dt

Linearisation at (ē, δ̄):
    A = [[1,  v·cos(e_psi)·dt ],    B = [[         0           ]
         [0,       1          ]]        [ v·dt / (L·cos²(δ)) ]]

Speed uses the global two-pass profile (same as stanley / lqr).
Nearest-point search is monotonically forward to avoid oscillation.

Usage:
    ros2 run auto_nav ilqr
    ros2 run auto_nav ilqr --ros-args -p N:=12 -p n_iter:=4 -p q_cte:=2.0
"""

import rclpy
from rclpy.node import Node
import math
import numpy as np

from nav_msgs.msg import Path, Odometry
from visualization_msgs.msg import Marker, MarkerArray
from vehiclecontrol_msgs.msg import VehicleControl


class ILQRController(Node):
    def __init__(self):
        super().__init__('ilqr_controller')

        # iLQR horizon and iterations.
        self.declare_parameter('N',                  10)    # prediction steps
        self.declare_parameter('dt',                  0.1)  # model timestep (s)
        self.declare_parameter('n_iter',              3)    # iLQR iterations per tick

        # Cost weights.
        self.declare_parameter('q_cte',              2.0)
        self.declare_parameter('q_psi',              1.0)
        self.declare_parameter('r_steer',            0.1)

        # Speed profile.
        self.declare_parameter('v_max',              8.0)
        self.declare_parameter('v_min',              1.5)
        self.declare_parameter('a_accel',            4.0)
        self.declare_parameter('a_brake',            8.0)
        self.declare_parameter('lat_accel_limit',    8.0)

        # Vehicle / limits.
        self.declare_parameter('wheelbase',          1.53)
        self.declare_parameter('max_steering',       0.6)
        self.declare_parameter('steering_alpha',     0.2)
        self.declare_parameter('max_gas',            0.6)
        self.declare_parameter('min_gas',            0.1)

        def gp(n): return self.get_parameter(n).get_parameter_value().double_value
        def gi(n): return self.get_parameter(n).get_parameter_value().integer_value

        self.N               = gi('N')
        self.dt              = gp('dt')
        self.n_iter          = gi('n_iter')
        self.q_cte           = gp('q_cte')
        self.q_psi           = gp('q_psi')
        self.r_steer         = gp('r_steer')
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
        self.R = self.r_steer   # scalar (1D control)

        # Path data — populated once when /map/path arrives.
        self.path_pts  = None
        self.path_yaws = None
        self.kappas    = None
        self.v_profile = None

        self.car_x         = 0.0
        self.car_y         = 0.0
        self.car_yaw       = 0.0
        self.car_speed     = 0.0
        self.prev_steering = 0.0
        self._nearest_idx  = 0

        # Warm-start: previous optimised control sequence.
        self.u_prev = np.zeros(self.N)

        self.create_subscription(Path,     '/map/path',      self._path_cb, 10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb, 10)

        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.viz_pub = self.create_publisher(MarkerArray,    '/ilqr/debug',              10)

        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'iLQR controller started — '
            f'N={self.N} dt={self.dt}s n_iter={self.n_iter}  '
            f'Q=[{self.q_cte},{self.q_psi}] R={self.r_steer}'
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

        # Central-difference tangents — smooths out per-point cone noise.
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

        self.path_pts      = pts
        self.path_yaws     = yaws
        self.kappas        = kappas
        self.v_profile     = self._two_pass_profile(pts, kappas)
        self._nearest_idx  = 0
        self.u_prev        = np.zeros(self.N)

        self.get_logger().info(
            f'Path ready — {n} pts  '
            f'v: {self.v_profile.min():.1f}–{self.v_profile.max():.1f} m/s'
        )

    def _two_pass_profile(self, pts, kappas):
        n  = len(pts)
        ds = np.array([np.linalg.norm(pts[(k + 1) % n] - pts[k]) for k in range(n)])
        v  = np.clip(
            np.where(kappas > 1e-4,
                     np.sqrt(self.lat_accel_limit / np.maximum(kappas, 1e-4)),
                     self.v_max),
            self.v_min, self.v_max,
        )
        for _ in range(2):
            for k in range(n):
                nxt    = (k + 1) % n
                v[nxt] = min(v[nxt], math.sqrt(v[k] ** 2 + 2 * self.a_accel * ds[k]))
        for _ in range(2):
            for k in range(n - 1, -1, -1):
                prv    = (k - 1) % n
                v[prv] = min(v[prv], math.sqrt(v[k] ** 2 + 2 * self.a_brake * ds[prv]))
        return np.clip(v, self.v_min, self.v_max)

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

    # ── iLQR ─────────────────────────────────────────────────────────────────

    def _solve(self, e_cte0, e_psi0, v, kappas_h):
        """Run n_iter iLQR passes and return the first optimal control."""
        N   = self.N
        dt  = self.dt
        L   = self.wheelbase
        Q   = self.Q
        R   = self.R
        v_e = max(v, 0.5)   # effective speed (avoid near-zero in dynamics)

        U = self.u_prev.copy()

        for _ in range(self.n_iter):

            # ── Forward rollout ──────────────────────────────────────────────
            E = np.zeros((N + 1, 2))
            E[0] = [e_cte0, e_psi0]
            for k in range(N):
                ec, ep = E[k]
                d      = U[k]
                kappa  = kappas_h[k]
                E[k + 1, 0] = ec + v_e * math.sin(ep) * dt
                E[k + 1, 1] = ep + v_e / L * math.tan(d) * dt - kappa * v_e * dt

            # ── Backward pass (Riccati recursion) ───────────────────────────
            ks = np.zeros(N)        # feedforward  (scalar per step)
            Ks = np.zeros((N, 2))   # feedback row (1×2 per step)

            Vx  = Q @ E[N]          # terminal gradient
            Vxx = Q.copy()          # terminal Hessian

            for k in range(N - 1, -1, -1):
                ec, ep = E[k]
                d      = U[k]

                # Linearise nonlinear dynamics at current rollout point.
                A = np.array([[1.0, v_e * math.cos(ep) * dt],
                              [0.0, 1.0                    ]])
                cos2 = math.cos(d) ** 2 + 1e-9
                B = np.array([[0.0               ],
                              [v_e * dt / (L * cos2)]])

                # Stage cost derivatives  (l = ½ eᵀQe + ½ Rδ²).
                lx  = Q  @ np.array([ec, ep])
                lu  = R  * d
                lxx = Q
                luu = R                         # scalar
                lux = np.zeros((1, 2))

                # Q-function terms.
                Quu = luu + float(B.T @ Vxx @ B)          # scalar
                Qux = lux + B.T @ Vxx @ A                  # (1,2)
                Qu  = lu  + float(B.T @ Vx)                # scalar
                Qxx = lxx + A.T @ Vxx @ A                  # (2,2)
                Qx  = lx  + A.T @ Vx                       # (2,)

                # Regularise Quu to keep it positive-definite.
                Quu_inv = 1.0 / (Quu + 1e-6)

                ks[k]   = float(-Quu_inv * Qu)
                Ks[k]   = (-Quu_inv * Qux)[0]  # (2,)

                # Riccati update.
                Vx  = Qx  + Ks[k] @ (Quu * ks[k]) + Qux.T.flatten() * ks[k]
                Vx  = Qx  - Qux.T.flatten() * Quu_inv * Qu
                Vxx = Qxx - Quu_inv * (Qux.T @ Qux)

            # ── Forward update (full step, α=1) ─────────────────────────────
            E_new = np.zeros((N + 1, 2))
            U_new = np.zeros(N)
            E_new[0] = [e_cte0, e_psi0]

            for k in range(N):
                dx      = E_new[k] - E[k]
                delta   = U[k] + ks[k] + Ks[k] @ dx
                U_new[k] = float(np.clip(delta, -self.max_steering, self.max_steering))
                ec, ep   = E_new[k]
                kappa    = kappas_h[k]
                E_new[k + 1, 0] = ec + v_e * math.sin(ep) * dt
                E_new[k + 1, 1] = ep + v_e / L * math.tan(U_new[k]) * dt - kappa * v_e * dt

            U = U_new

        # Warm-start next tick with the solution shifted by one step.
        self.u_prev      = np.empty(N)
        self.u_prev[:-1] = U[1:]
        self.u_prev[-1]  = 0.0

        return float(U[0])

    # ── Control loop ─────────────────────────────────────────────────────────

    def _control_loop(self):
        if self.path_pts is None:
            return

        pts = self.path_pts
        n   = len(pts)
        car = np.array([self.car_x, self.car_y])

        # Monotonic nearest-point search (window of 10 ahead).
        window  = 10
        indices = [(self._nearest_idx + i) % n for i in range(window)]
        local   = int(np.argmin(np.linalg.norm(pts[indices] - car, axis=1)))
        self._nearest_idx = indices[local]
        nearest = self._nearest_idx

        # Initial error state.
        tx    = math.cos(self.path_yaws[nearest])
        ty    = math.sin(self.path_yaws[nearest])
        dx    = self.car_x - pts[nearest, 0]
        dy    = self.car_y - pts[nearest, 1]
        e_cte = -(tx * dy - ty * dx)
        e_psi = self.path_yaws[nearest] - self.car_yaw
        e_psi = math.atan2(math.sin(e_psi), math.cos(e_psi))

        # Curvatures over the horizon.
        kappas_h = np.array([self.kappas[(nearest + k) % n] for k in range(self.N)])

        # Solve iLQR.
        steering = self._solve(e_cte, e_psi, self.car_speed, kappas_h)

        # Smoothing filter.
        steering = (self.steering_alpha * steering +
                   (1.0 - self.steering_alpha) * self.prev_steering)
        steering = float(np.clip(steering, -self.max_steering, self.max_steering))
        self.prev_steering = steering

        # Speed from global profile.
        v_target = float(self.v_profile[nearest])
        if self.car_speed > v_target:
            gas   = 0.0
            brake = float(np.clip(
                (self.car_speed - v_target) / max(v_target, 0.1), 0.0, 1.0))
        else:
            headroom = min(v_target - self.car_speed, 2.0) / 2.0
            gas      = float(np.clip(
                self.min_gas + (self.max_gas - self.min_gas) * headroom,
                self.min_gas, self.max_gas))
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
                f'δ={math.degrees(steering):.1f}°  '
                f'spd={self.car_speed:.1f}  v_tgt={v_target:.1f}  '
                f'gas={gas:.2f}  brake={brake:.2f}'
            )

    # ── Debug visualisation ───────────────────────────────────────────────────

    def _publish_debug(self, nearest_pt, cte):
        stamp = self.get_clock().now().to_msg()
        ma    = MarkerArray()
        m     = Marker()
        m.header.frame_id    = 'Obj_F'
        m.header.stamp       = stamp
        m.ns, m.id           = 'ilqr', 0
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
    node = ILQRController()
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
