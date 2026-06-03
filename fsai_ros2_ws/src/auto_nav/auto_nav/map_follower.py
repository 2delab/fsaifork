#!/usr/bin/env python3
"""
Map Follower
============
Pure-pursuit controller driven entirely by the global path on /map/path.

No cone perception is used at runtime — the node relies on the pre-computed
track centreline published by array_map or object_list_global_planner.

Steering
--------
Adaptive pure pursuit: the lookahead distance scales with current speed so
the car looks further ahead the faster it is going.  A steering-rate smoother
removes jitter from discretised path points.

Speed planning
--------------
Two-pass global velocity profile (identical to stanley.py):

  Forward pass  — propagates v² + 2·a·ds limits around the loop so the car
                  never accelerates beyond the kinematics allow.
  Backward pass — propagates braking backwards so the car always arrives at
                  every corner at the right speed.

Running each pass twice converges the profile on a closed loop.

The profile is recomputed once whenever a new path arrives.  During the
control tick the node reads the target speed for the nearest path point and
applies proportional gas or a linear brake ramp.

Usage:
    ros2 run auto_nav map_follower
    ros2 run auto_nav map_follower --ros-args -p max_gas:=0.5 -p v_max:=10.0
"""

import math

import numpy as np
import rclpy
from rclpy.node import Node

from nav_msgs.msg import Odometry, Path
from vehiclecontrol_msgs.msg import VehicleControl
from visualization_msgs.msg import Marker, MarkerArray


class MapFollower(Node):
    def __init__(self):
        super().__init__('map_follower')

        # --- Lookahead ---
        self.declare_parameter('lookahead_time',   1.5)   # s   adaptive scale
        self.declare_parameter('min_lookahead',    3.0)   # m   floor
        self.declare_parameter('max_lookahead',   20.0)   # m   ceiling

        # --- Speed profile ---
        self.declare_parameter('v_max',            8.0)   # m/s top speed
        self.declare_parameter('v_min',            1.5)   # m/s minimum speed
        self.declare_parameter('a_accel',          4.0)   # m/s² max acceleration
        self.declare_parameter('a_brake',          8.0)   # m/s² max braking
        self.declare_parameter('lat_accel_limit',  8.0)   # m/s² cornering cap

        # --- Throttle / brake ---
        self.declare_parameter('max_gas',          0.6)
        self.declare_parameter('min_gas',          0.1)

        # --- Steering ---
        self.declare_parameter('max_steering',     0.6)   # rad (~34°)
        self.declare_parameter('wheelbase',        1.53)  # m
        self.declare_parameter('steering_alpha',   0.3)   # low-pass factor [0,1]

        def gp(n):
            return self.get_parameter(n).get_parameter_value().double_value

        self.lookahead_time   = gp('lookahead_time')
        self.min_lookahead    = gp('min_lookahead')
        self.max_lookahead    = gp('max_lookahead')
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

        # Runtime state
        self.path_pts      = None   # np.array (N, 2) world frame
        self.v_profile     = None   # np.array (N,)   m/s target at each point
        self.car_x         = 0.0
        self.car_y         = 0.0
        self.car_yaw       = 0.0
        self.car_speed     = 0.0
        self.prev_steering = 0.0

        # Subscriptions
        self.create_subscription(Path,     '/map/path',      self._path_cb, 10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb,  10)

        # Publishers
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.viz_pub = self.create_publisher(MarkerArray,    '/map_follower/debug',       10)

        # Control timer — 50 Hz
        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'Map Follower started — '
            f'lookahead {self.min_lookahead}–{self.max_lookahead} m @ {self.lookahead_time} s/m  '
            f'v_max={self.v_max} m/s  lat_accel={self.lat_accel_limit} m/s²'
        )

    # ── Subscribers ──────────────────────────────────────────────────────────

    def _path_cb(self, msg: Path) -> None:
        """Receive full track centreline and (re-)compute the global speed profile."""
        if not msg.poses:
            return
        pts = np.array(
            [(p.pose.position.x, p.pose.position.y) for p in msg.poses],
            dtype=float,
        )
        self.path_pts  = pts
        self.v_profile = self._compute_speed_profile(pts)

    def _odom_cb(self, msg: Odometry) -> None:
        """Unpack car pose and velocity from odometry."""
        self.car_x = msg.pose.pose.position.x
        self.car_y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        self.car_yaw = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )
        self.car_speed = math.sqrt(
            msg.twist.twist.linear.x ** 2 +
            msg.twist.twist.linear.y ** 2
        )

    # ── Speed profile ────────────────────────────────────────────────────────

    def _compute_speed_profile(self, pts: np.ndarray) -> np.ndarray:
        """Global two-pass velocity profile for the full closed-loop path.

        Forward pass  — propagates acceleration limits around the track.
        Backward pass — propagates braking limits so the car always arrives at
                        each corner already at the right speed.
        Running each pass twice guarantees convergence on a closed loop.
        """
        n  = len(pts)
        ds = np.array([np.linalg.norm(pts[(k + 1) % n] - pts[k]) for k in range(n)])

        # Menger curvature at every point.
        kappas = np.zeros(n)
        for k in range(n):
            v1 = pts[k]           - pts[(k - 1) % n]
            v2 = pts[(k + 1) % n] - pts[k]
            l1, l2 = np.linalg.norm(v1), np.linalg.norm(v2)
            if l1 > 0 and l2 > 0:
                cross     = abs(v1[0] * v2[1] - v1[1] * v2[0])
                kappas[k] = cross / (l1 * l2 * (l1 + l2) / 2.0 + 1e-9)

        # Lateral-acceleration speed cap at each point.
        v_lat = np.where(
            kappas > 1e-4,
            np.sqrt(self.lat_accel_limit / np.maximum(kappas, 1e-4)),
            self.v_max,
        )
        v_lat = np.clip(v_lat, self.v_min, self.v_max)

        # Forward pass (run twice to close the loop).
        v = v_lat.copy()
        for _ in range(2):
            for k in range(n):
                nxt    = (k + 1) % n
                v_reach = math.sqrt(v[k] ** 2 + 2.0 * self.a_accel * ds[k])
                v[nxt]  = min(v[nxt], v_reach)

        # Backward pass (run twice to close the loop).
        for _ in range(2):
            for k in range(n - 1, -1, -1):
                prv    = (k - 1) % n
                v_reach = math.sqrt(v[k] ** 2 + 2.0 * self.a_brake * ds[prv])
                v[prv]  = min(v[prv], v_reach)

        profile = np.clip(v, self.v_min, self.v_max)
        self.get_logger().info(
            f'Speed profile computed — {n} pts  '
            f'min={profile.min():.1f} m/s  max={profile.max():.1f} m/s  '
            f'mean={profile.mean():.1f} m/s'
        )
        return profile

    # ── Path helpers ─────────────────────────────────────────────────────────

    def _closest_idx(self) -> int:
        """Index of the path point nearest to the current car position."""
        car = np.array([self.car_x, self.car_y])
        return int(np.argmin(np.linalg.norm(self.path_pts - car, axis=1)))

    def _point_at_dist(self, start_idx: int, distance: float) -> np.ndarray:
        """Interpolated path point exactly `distance` metres ahead of start_idx.

        Walks forward along the path (wrapping on a closed loop) and linearly
        interpolates within the segment that crosses the target distance.
        """
        pts = self.path_pts
        n   = len(pts)
        accumulated = 0.0
        idx = start_idx
        for _ in range(n):
            nxt  = (idx + 1) % n
            step = float(np.linalg.norm(pts[nxt] - pts[idx]))
            if accumulated + step >= distance:
                t = (distance - accumulated) / (step + 1e-9)
                return pts[idx] + t * (pts[nxt] - pts[idx])
            accumulated += step
            idx = nxt
        return pts[idx]

    # ── Control loop ─────────────────────────────────────────────────────────

    def _control_loop(self) -> None:
        if self.path_pts is None or self.v_profile is None:
            return

        # ── Nearest path point ────────────────────────────────────────────
        nearest = self._closest_idx()

        # ── Adaptive lookahead ────────────────────────────────────────────
        # Look further ahead at higher speed; clamp to [min, max].
        lookahead = float(np.clip(
            self.lookahead_time * self.car_speed,
            self.min_lookahead,
            self.max_lookahead,
        ))
        target = self._point_at_dist(nearest, lookahead)

        # ── Pure-pursuit steering ─────────────────────────────────────────
        # Transform target into vehicle frame.
        dx, dy     = target[0] - self.car_x, target[1] - self.car_y
        cos_y, sin_y = math.cos(self.car_yaw), math.sin(self.car_yaw)
        local_x    =  dx * cos_y + dy * sin_y
        local_y    = -dx * sin_y + dy * cos_y

        L = math.sqrt(local_x ** 2 + local_y ** 2)
        if L > 0.5:
            curvature = (2.0 * local_y) / (L * L)
            raw_steer = math.atan(curvature * self.wheelbase)
        else:
            raw_steer = 0.0

        # Low-pass smoothing then hard clamp.
        steer = (self.steering_alpha * raw_steer
                 + (1.0 - self.steering_alpha) * self.prev_steering)
        steer = float(np.clip(steer, -self.max_steering, self.max_steering))
        self.prev_steering = steer

        # ── Speed control from precomputed global profile ─────────────────
        v_target = float(self.v_profile[nearest])

        if self.car_speed > v_target:
            gas   = 0.0
            brake = float(np.clip(
                (self.car_speed - v_target) / max(v_target, 0.1),
                0.0, 1.0,
            ))
        else:
            headroom = min(v_target - self.car_speed, 2.0) / 2.0
            gas   = float(np.clip(
                self.min_gas + (self.max_gas - self.min_gas) * headroom,
                self.min_gas, self.max_gas,
            ))
            brake = 0.0

        # ── Publish command ───────────────────────────────────────────────
        cmd               = VehicleControl()
        cmd.use_vc        = True
        cmd.selector_ctrl = 1
        cmd.gas           = gas
        cmd.brake         = brake
        cmd.steer_ang     = steer
        self.cmd_pub.publish(cmd)

        self._publish_debug(target, lookahead, nearest)

        if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:
            self.get_logger().info(
                f'spd={self.car_speed:.1f} m/s  v_tgt={v_target:.1f} m/s  '
                f'la={lookahead:.1f} m  steer={math.degrees(steer):.1f}°  '
                f'gas={gas:.2f}  brake={brake:.2f}'
            )

    # ── Debug visualisation ───────────────────────────────────────────────────

    def _publish_debug(self, target: np.ndarray, lookahead: float, nearest_idx: int) -> None:
        stamp = self.get_clock().now().to_msg()
        ma    = MarkerArray()

        # Lookahead target point — colour shifts blue→red with lookahead distance.
        t_m = Marker()
        t_m.header.frame_id    = 'Obj_F'
        t_m.header.stamp       = stamp
        t_m.ns, t_m.id         = 'map_follower', 0
        t_m.type               = Marker.SPHERE
        t_m.action             = Marker.ADD
        t_m.pose.position.x    = float(target[0])
        t_m.pose.position.y    = float(target[1])
        t_m.pose.orientation.w = 1.0
        frac = float(np.clip(
            (lookahead - self.min_lookahead) / max(self.max_lookahead - self.min_lookahead, 1e-9),
            0.0, 1.0,
        ))
        t_m.scale.x = t_m.scale.y = t_m.scale.z = max(0.3, frac * 0.8 + 0.2)
        t_m.color.r = frac
        t_m.color.b = 1.0 - frac
        t_m.color.a = 1.0
        t_m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        ma.markers.append(t_m)

        # Nearest path point — green dot.
        n_m = Marker()
        n_m.header.frame_id    = 'Obj_F'
        n_m.header.stamp       = stamp
        n_m.ns, n_m.id         = 'map_follower', 1
        n_m.type               = Marker.SPHERE
        n_m.action             = Marker.ADD
        n_m.pose.position.x    = float(self.path_pts[nearest_idx, 0])
        n_m.pose.position.y    = float(self.path_pts[nearest_idx, 1])
        n_m.pose.orientation.w = 1.0
        n_m.scale.x = n_m.scale.y = n_m.scale.z = 0.25
        n_m.color.g = 1.0
        n_m.color.a = 1.0
        n_m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        ma.markers.append(n_m)

        # Speed profile at nearest point — text label.
        v_target = float(self.v_profile[nearest_idx])
        txt = Marker()
        txt.header.frame_id    = 'Obj_F'
        txt.header.stamp       = stamp
        txt.ns, txt.id         = 'map_follower', 2
        txt.type               = Marker.TEXT_VIEW_FACING
        txt.action             = Marker.ADD
        txt.pose.position.x    = float(self.path_pts[nearest_idx, 0])
        txt.pose.position.y    = float(self.path_pts[nearest_idx, 1])
        txt.pose.position.z    = 1.0
        txt.pose.orientation.w = 1.0
        txt.scale.z            = 0.4
        txt.color.r = txt.color.g = txt.color.b = txt.color.a = 1.0
        txt.text               = f'{v_target:.1f} m/s'
        txt.lifetime           = rclpy.duration.Duration(seconds=0.1).to_msg()
        ma.markers.append(txt)

        self.viz_pub.publish(ma)


def main(args=None):
    rclpy.init(args=args)
    node = MapFollower()
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
