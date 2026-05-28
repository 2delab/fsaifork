#!/usr/bin/env python3
"""
Stanley Controller
==================
Geometric path-tracking controller developed by Stanford's DARPA team.

Unlike pure pursuit (which chases a lookahead point), Stanley minimises two
errors simultaneously at the front axle:
  - Heading error  ψ_e : difference between path tangent and car heading
  - Cross-track error e : signed lateral distance of front axle from path

Steering law:  δ = ψ_e + arctan(k · e / v)

The arctan term drives the front axle back onto the path; heading error
drives the car parallel to it. Both decay to zero together.

Speed is planned by scanning the path curvature over a preview window and
targeting v_safe = sqrt(lat_accel_limit / κ_max).

Usage:
    ros2 run auto_nav stanley
    ros2 run auto_nav stanley --ros-args -p k:=1.5 -p max_gas:=0.5
"""

import rclpy
from rclpy.node import Node
import math
import numpy as np

from nav_msgs.msg import Path, Odometry
from visualization_msgs.msg import Marker, MarkerArray
from vehiclecontrol_msgs.msg import VehicleControl


class StanleyController(Node):
    def __init__(self):
        super().__init__('stanley_controller')

        # Stanley gain — higher k corrects cross-track error more aggressively.
        self.declare_parameter('k',                  1.0)
        # Minimum effective speed used in the arctan denominator (avoids div/0
        # at standstill and limits maximum correction at very low speed).
        self.declare_parameter('k_soft',             0.5)   # m/s

        # Speed planning — global two-pass velocity profile.
        self.declare_parameter('v_max',             8.0)    # m/s top speed
        self.declare_parameter('v_min',             1.5)    # m/s minimum speed
        self.declare_parameter('a_accel',           4.0)    # m/s² max acceleration
        self.declare_parameter('a_brake',           8.0)    # m/s² max braking
        self.declare_parameter('lat_accel_limit',   8.0)    # m/s² cornering limit
        self.declare_parameter('max_gas',           0.6)
        self.declare_parameter('min_gas',           0.1)

        # Steering limits.
        self.declare_parameter('max_steering',       0.6)   # rad (~34°)
        self.declare_parameter('wheelbase',          1.53)  # m
        self.declare_parameter('steering_alpha',     0.3)   # smoothing factor

        def gp(n):
            return self.get_parameter(n).get_parameter_value().double_value

        self.k                = gp('k')
        self.k_soft           = gp('k_soft')
        self.v_max            = gp('v_max')
        self.v_min            = gp('v_min')
        self.a_accel          = gp('a_accel')
        self.a_brake          = gp('a_brake')
        self.lat_accel_limit  = gp('lat_accel_limit')
        self.max_gas          = gp('max_gas')
        self.min_gas          = gp('min_gas')
        self.max_steering     = gp('max_steering')
        self.wheelbase        = gp('wheelbase')
        self.steering_alpha   = gp('steering_alpha')

        self.path_pts  = None   # np.array (N, 2) world frame
        self.v_profile = None   # np.array (N,)   target speed at each point
        self.car_x         = 0.0
        self.car_y         = 0.0
        self.car_yaw       = 0.0
        self.car_speed     = 0.0
        self.prev_steering = 0.0

        self.create_subscription(Path,     '/map/path',      self._path_cb, 10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb, 10)

        self.cmd_pub  = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.viz_pub  = self.create_publisher(MarkerArray,    '/stanley/debug',            10)

        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'Stanley controller started — k={self.k}  k_soft={self.k_soft} m/s  '
            f'lat_accel={self.lat_accel_limit} m/s²'
        )

    # ── Subscribers ──────────────────────────────────────────────────────────

    def _path_cb(self, msg):
        if not msg.poses:
            return
        pts = np.array(
            [(p.pose.position.x, p.pose.position.y) for p in msg.poses],
            dtype=float,
        )
        self.path_pts  = pts
        self.v_profile = self._compute_speed_profile(pts)

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

    # ── Core helpers ─────────────────────────────────────────────────────────

    def _path_tangent(self, idx):
        """Unit tangent vector of the path at index idx."""
        n    = len(self.path_pts)
        nxt  = (idx + 1) % n
        v    = self.path_pts[nxt] - self.path_pts[idx]
        norm = np.linalg.norm(v)
        return v / norm if norm > 1e-9 else np.array([1.0, 0.0])

    def _compute_speed_profile(self, pts):
        """Global two-pass velocity profile for the full closed-loop path.

        Forward pass  — propagates acceleration limits around the track.
        Backward pass — propagates braking limits so the car always arrives at
                        each corner already at the right speed.
        Running each pass 2× guarantees convergence on a closed loop.
        """
        n  = len(pts)
        ds = np.array([np.linalg.norm(pts[(k + 1) % n] - pts[k]) for k in range(n)])

        # Curvature at every point (Menger).
        kappas = np.zeros(n)
        for k in range(n):
            v1 = pts[k]           - pts[(k - 1) % n]
            v2 = pts[(k + 1) % n] - pts[k]
            l1, l2 = np.linalg.norm(v1), np.linalg.norm(v2)
            if l1 > 0 and l2 > 0:
                cross      = abs(v1[0] * v2[1] - v1[1] * v2[0])
                kappas[k]  = cross / (l1 * l2 * (l1 + l2) / 2.0 + 1e-9)

        # Lateral-acceleration speed cap at each point.
        v_lat = np.where(kappas > 1e-4,
                         np.sqrt(self.lat_accel_limit / np.maximum(kappas, 1e-4)),
                         self.v_max)
        v_lat = np.clip(v_lat, self.v_min, self.v_max)

        # Forward pass (run twice to close the loop).
        v = v_lat.copy()
        for _ in range(2):
            for k in range(n):
                nxt     = (k + 1) % n
                v_reach = math.sqrt(v[k] ** 2 + 2.0 * self.a_accel * ds[k])
                v[nxt]  = min(v[nxt], v_reach)

        # Backward pass (run twice to close the loop).
        for _ in range(2):
            for k in range(n - 1, -1, -1):
                prv     = (k - 1) % n
                v_reach = math.sqrt(v[k] ** 2 + 2.0 * self.a_brake * ds[prv])
                v[prv]  = min(v[prv], v_reach)

        profile = np.clip(v, self.v_min, self.v_max)
        self.get_logger().info(
            f'Speed profile computed — '
            f'min={profile.min():.1f} m/s  max={profile.max():.1f} m/s  '
            f'mean={profile.mean():.1f} m/s'
        )
        return profile

    # ── Control loop ─────────────────────────────────────────────────────────

    def _control_loop(self):
        if self.path_pts is None or self.v_profile is None:
            return

        pts = self.path_pts
        n   = len(pts)

        # Front axle position (Stanley tracks the front axle, not the CoG).
        x_fa = self.car_x + self.wheelbase * math.cos(self.car_yaw)
        y_fa = self.car_y + self.wheelbase * math.sin(self.car_yaw)
        fa   = np.array([x_fa, y_fa])

        # Nearest path point to the front axle.
        nearest = int(np.argmin(np.linalg.norm(pts - fa, axis=1)))

        # Path tangent and heading at nearest point.
        tx, ty        = self._path_tangent(nearest)
        path_heading  = math.atan2(ty, tx)

        # Heading error: wrap to (−π, π).
        heading_err = path_heading - self.car_yaw
        heading_err = math.atan2(math.sin(heading_err), math.cos(heading_err))

        # Cross-track error (signed).
        # e > 0  →  front axle is to the RIGHT of path  →  steer LEFT  →  +δ
        dx = x_fa - pts[nearest, 0]
        dy = y_fa - pts[nearest, 1]
        e  = -(tx * dy - ty * dx)   # ty·dx − tx·dy

        # Stanley steering law.
        v_eff   = max(self.car_speed, self.k_soft)
        stanley = heading_err + math.atan2(self.k * e, v_eff)
        stanley = self.steering_alpha * stanley + (1.0 - self.steering_alpha) * self.prev_steering
        stanley = float(np.clip(stanley, -self.max_steering, self.max_steering))
        self.prev_steering = stanley

        # Speed target from precomputed global profile — no reactive scan needed.
        v_target = float(self.v_profile[nearest])

        if self.car_speed > v_target:
            gas   = 0.0
            brake = float(np.clip((self.car_speed - v_target) / max(v_target, 0.1), 0.0, 1.0))
        else:
            headroom = min(v_target - self.car_speed, 2.0) / 2.0
            gas      = float(np.clip(self.min_gas + (self.max_gas - self.min_gas) * headroom,
                                     self.min_gas, self.max_gas))
            brake    = 0.0

        cmd               = VehicleControl()
        cmd.use_vc        = True
        cmd.selector_ctrl = 1
        cmd.gas           = gas
        cmd.brake         = brake
        cmd.steer_ang     = stanley
        self.cmd_pub.publish(cmd)

        self._publish_debug(x_fa, y_fa, pts[nearest], stanley, e)

        if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:
            self.get_logger().info(
                f'e={e:.3f}m  ψ_e={math.degrees(heading_err):.1f}°  '
                f'δ={math.degrees(stanley):.1f}°  '
                f'spd={self.car_speed:.1f}  v_tgt={v_target:.1f}  '
                f'gas={gas:.2f}  brake={brake:.2f}'
            )

    def _publish_debug(self, x_fa, y_fa, nearest_pt, steering, cte):
        stamp = self.get_clock().now().to_msg()
        ma    = MarkerArray()

        # Front axle position.
        fa_m = Marker()
        fa_m.header.frame_id    = 'Obj_F'
        fa_m.header.stamp       = stamp
        fa_m.ns, fa_m.id        = 'stanley', 0
        fa_m.type               = Marker.SPHERE
        fa_m.action             = Marker.ADD
        fa_m.pose.position.x    = x_fa
        fa_m.pose.position.y    = y_fa
        fa_m.pose.orientation.w = 1.0
        fa_m.scale.x = fa_m.scale.y = fa_m.scale.z = 0.3
        fa_m.color.r = 1.0
        fa_m.color.a = 1.0
        fa_m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        ma.markers.append(fa_m)

        # Nearest path point.
        np_m = Marker()
        np_m.header.frame_id    = 'Obj_F'
        np_m.header.stamp       = stamp
        np_m.ns, np_m.id        = 'stanley', 1
        np_m.type               = Marker.SPHERE
        np_m.action             = Marker.ADD
        np_m.pose.position.x    = float(nearest_pt[0])
        np_m.pose.position.y    = float(nearest_pt[1])
        np_m.pose.orientation.w = 1.0
        np_m.scale.x = np_m.scale.y = np_m.scale.z = 0.3
        # Colour by CTE magnitude: green=on-path, red=large error.
        np_m.color.r = float(min(abs(cte) / 1.0, 1.0))
        np_m.color.g = float(1.0 - min(abs(cte) / 1.0, 1.0))
        np_m.color.a = 1.0
        np_m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        ma.markers.append(np_m)

        self.viz_pub.publish(ma)


def main(args=None):
    rclpy.init(args=args)
    node = StanleyController()
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
