#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import math
import numpy as np

from nav_msgs.msg import Path, Odometry
from visualization_msgs.msg import Marker
from vehiclecontrol_msgs.msg import VehicleControl


class AdaptivePursuitController(Node):
    def __init__(self):
        super().__init__('adaptive_pursuit')

        # --- Lookahead ---
        self.declare_parameter('lookahead_time',    1.5)   # seconds ahead to look
        self.declare_parameter('min_lookahead',     3.0)   # metres
        self.declare_parameter('max_lookahead',    20.0)   # metres

        # --- Speed ---
        self.declare_parameter('max_gas',           0.4)
        self.declare_parameter('min_gas',           0.1)
        self.declare_parameter('lat_accel_limit',   8.0)   # m/s² lateral accel cap
        self.declare_parameter('preview_distance', 15.0)   # metres ahead to scan curvature

        # --- Steering ---
        self.declare_parameter('max_steering',      0.6)   # rad
        self.declare_parameter('wheelbase',         1.53)  # metres
        self.declare_parameter('steering_alpha',    0.3)   # smoothing factor

        def gp(name):
            return self.get_parameter(name).get_parameter_value().double_value

        self.lookahead_time     = gp('lookahead_time')
        self.min_lookahead      = gp('min_lookahead')
        self.max_lookahead      = gp('max_lookahead')
        self.max_gas            = gp('max_gas')
        self.min_gas            = gp('min_gas')
        self.lat_accel_limit    = gp('lat_accel_limit')
        self.preview_distance   = gp('preview_distance')
        self.max_steering       = gp('max_steering')
        self.wheelbase          = gp('wheelbase')
        self.steering_alpha     = gp('steering_alpha')

        self.path_pts      = None   # np.array (N, 2) world frame
        self.path_seg_lens = None   # cumulative arc lengths along path
        self.car_x         = 0.0
        self.car_y         = 0.0
        self.car_yaw       = 0.0
        self.car_speed     = 0.0
        self.prev_steering = 0.0

        self.create_subscription(Path,     '/map/path',      self._path_cb, 10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb, 10)

        self.cmd_pub        = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.target_viz_pub = self.create_publisher(Marker, '/adaptive_pursuit/target', 10)

        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'Adaptive Pursuit started — '
            f'lookahead={self.min_lookahead}–{self.max_lookahead}m '
            f'@ {self.lookahead_time}s, '
            f'lat_accel_limit={self.lat_accel_limit}m/s²'
        )

    # ── Subscribers ──────────────────────────────────────────────────────────

    def _path_cb(self, msg):
        if not msg.poses:
            return
        pts = np.array(
            [(p.pose.position.x, p.pose.position.y) for p in msg.poses],
            dtype=float,
        )
        self.path_pts = pts
        # Precompute cumulative arc lengths for distance-along-path queries.
        diffs = np.linalg.norm(np.diff(pts, axis=0), axis=1)
        self.path_seg_lens = np.concatenate([[0.0], np.cumsum(diffs)])

    def _odom_cb(self, msg):
        self.car_x     = msg.pose.pose.position.x
        self.car_y     = msg.pose.pose.position.y
        q              = msg.pose.pose.orientation
        self.car_yaw   = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )
        self.car_speed = math.sqrt(
            msg.twist.twist.linear.x ** 2 +
            msg.twist.twist.linear.y ** 2
        )

    # ── Core helpers ─────────────────────────────────────────────────────────

    def _closest_idx(self):
        car = np.array([self.car_x, self.car_y])
        return int(np.argmin(np.linalg.norm(self.path_pts - car, axis=1)))

    def _point_at_dist(self, start_idx, distance):
        """Return the path point `distance` metres ahead of start_idx (wraps)."""
        pts = self.path_pts
        n   = len(pts)
        accumulated = 0.0
        idx = start_idx
        while accumulated < distance:
            next_idx = (idx + 1) % n
            step = np.linalg.norm(pts[next_idx] - pts[idx])
            if accumulated + step >= distance:
                # Interpolate between idx and next_idx.
                t = (distance - accumulated) / (step + 1e-9)
                return pts[idx] + t * (pts[next_idx] - pts[idx])
            accumulated += step
            idx = next_idx
            if idx == start_idx:   # full loop with no match — return start
                break
        return pts[idx]

    def _max_curvature_ahead(self, start_idx, preview_dist):
        """Menger curvature at each path point in the preview window; return max."""
        pts  = self.path_pts
        n    = len(pts)
        kappas = []
        accumulated = 0.0
        idx = start_idx
        while accumulated < preview_dist:
            prev_idx = (idx - 1) % n
            next_idx = (idx + 1) % n
            v1 = pts[idx]      - pts[prev_idx]
            v2 = pts[next_idx] - pts[idx]
            l1, l2 = np.linalg.norm(v1), np.linalg.norm(v2)
            if l1 > 0 and l2 > 0:
                cross = abs(v1[0] * v2[1] - v1[1] * v2[0])
                kappas.append(cross / (l1 * l2 * (l1 + l2) / 2.0 + 1e-9))
            accumulated += l2 if l2 > 0 else 1e-3
            idx = next_idx
            if idx == start_idx:
                break
        return max(kappas) if kappas else 0.0

    # ── Control loop ─────────────────────────────────────────────────────────

    def _control_loop(self):
        if self.path_pts is None:
            return

        closest = self._closest_idx()

        # Adaptive lookahead: look further ahead at higher speed.
        lookahead = float(np.clip(
            self.lookahead_time * self.car_speed,
            self.min_lookahead,
            self.max_lookahead,
        ))

        lp = self._point_at_dist(closest, lookahead)

        # Transform lookahead point to vehicle frame.
        dx, dy   = lp[0] - self.car_x, lp[1] - self.car_y
        cos_y, sin_y = math.cos(self.car_yaw), math.sin(self.car_yaw)
        local_x  =  dx * cos_y + dy * sin_y
        local_y  = -dx * sin_y + dy * cos_y

        # Pure pursuit steering.
        L = math.sqrt(local_x ** 2 + local_y ** 2)
        if L > 0.5:
            curvature      = (2.0 * local_y) / (L * L)
            steering_angle = math.atan(curvature * self.wheelbase)
        else:
            steering_angle = 0.0

        steering_angle = (self.steering_alpha * steering_angle +
                         (1.0 - self.steering_alpha) * self.prev_steering)
        steering_angle = float(np.clip(steering_angle,
                                       -self.max_steering, self.max_steering))
        self.prev_steering = steering_angle

        # Speed planning: scan curvature over the preview window.
        # v_safe = sqrt(lat_accel_limit / kappa_max) — if curvature is zero use max speed.
        kappa_max = self._max_curvature_ahead(closest, self.preview_distance)
        if kappa_max > 1e-4:
            v_target = math.sqrt(self.lat_accel_limit / kappa_max)
        else:
            v_target = 1e9   # straight — no speed cap

        if self.car_speed > v_target:
            gas   = 0.0
            brake = min(1.0, (self.car_speed - v_target) / max(v_target, 0.1))
        else:
            headroom = max(0.0, v_target - self.car_speed)
            gas   = float(np.clip(
                self.min_gas + (self.max_gas - self.min_gas) * min(headroom, 2.0) / 2.0,
                self.min_gas, self.max_gas,
            ))
            brake = 0.0

        cmd = VehicleControl()
        cmd.use_vc        = True
        cmd.selector_ctrl = 1
        cmd.gas           = gas
        cmd.brake         = brake
        cmd.steer_ang     = steering_angle
        self.cmd_pub.publish(cmd)

        self._publish_target(lp, lookahead)

        if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:
            self.get_logger().info(
                f'spd={self.car_speed:.1f}m/s  v_target={v_target:.1f}m/s  '
                f'kappa={kappa_max:.3f}  la={lookahead:.1f}m  '
                f'steer={math.degrees(steering_angle):.1f}°  '
                f'gas={gas:.2f}  brake={brake:.2f}'
            )

    def _publish_target(self, lp, lookahead):
        m = Marker()
        m.header.frame_id    = 'Obj_F'
        m.header.stamp       = self.get_clock().now().to_msg()
        m.ns, m.id           = 'adaptive_pursuit', 0
        m.type               = Marker.SPHERE
        m.action             = Marker.ADD
        m.pose.position.x    = float(lp[0])
        m.pose.position.y    = float(lp[1])
        m.pose.orientation.w = 1.0
        sz = max(0.3, min(1.0, lookahead / self.max_lookahead))
        m.scale.x = m.scale.y = m.scale.z = sz
        m.color.r = 1.0 - sz   # blue at short lookahead, red at long
        m.color.b = sz
        m.color.a = 1.0
        m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        self.target_viz_pub.publish(m)


def main(args=None):
    rclpy.init(args=args)
    node = AdaptivePursuitController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        stop = VehicleControl()
        stop.use_vc        = True
        stop.selector_ctrl = 1
        stop.brake         = 1.0
        node.cmd_pub.publish(stop)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
