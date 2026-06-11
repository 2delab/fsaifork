#!/usr/bin/env python3
"""
Reactive Navigation — Delaunay Midpoints
==========================================
Subscribes to Cone3DArray from perception pipeline, classifies by color,
triangulates with Delaunay, extracts cross-track edges (left↔right),
computes midpoints as path waypoints, and drives via pure pursuit with
curvature-based braking.

Does NOT use odom. Does NOT use array_map. Preserves z height.

Usage:
    ros2 run auto_nav reactive_nav
    ros2 run auto_nav reactive_nav --ros-args -p lookahead_dist:=6.0 -p max_gas:=0.3
"""

import rclpy
from rclpy.node import Node
import math
import numpy as np

from visualization_msgs.msg import MarkerArray, Marker
from geometry_msgs.msg import Point
from vehiclecontrol_msgs.msg import VehicleControl
from rcl_interfaces.msg import SetParametersResult
from scipy.spatial import Delaunay
from fsai_interfaces.msg import Cone3DArray


class ReactiveNav(Node):
    def __init__(self):
        super().__init__('reactive_nav')

        # --- Parameters ---
        self.declare_parameter('wheelbase', 1.53)
        self.declare_parameter('lookahead_dist', 20.0)
        self.declare_parameter('max_gas', 0.1)
        self.declare_parameter('min_gas', 0.005)
        self.declare_parameter('wide_corridor', 5.0)
        self.declare_parameter('max_steering', 0.6)
        self.declare_parameter('steering_alpha', 0.35)
        self.declare_parameter('max_cone_range', 15.0)
        self.declare_parameter('boundary_clearance', 1.0)
        self.declare_parameter('preview_step', 5.0)
        self.declare_parameter('kappa_threshold', 0.05)
        self.declare_parameter('kappa_brake_gain', 4.0)
        self.declare_parameter('max_brake', 0.6)

        def gp(name):
            return self.get_parameter(name).get_parameter_value().double_value

        self.wheelbase = gp('wheelbase')
        self.lookahead_dist = gp('lookahead_dist')
        self.max_gas = gp('max_gas')
        self.min_gas = gp('min_gas')
        self.wide_corridor = gp('wide_corridor')
        self.max_steering = gp('max_steering')
        self.steering_alpha = gp('steering_alpha')
        self.max_cone_range = gp('max_cone_range')
        self.boundary_clearance = gp('boundary_clearance')
        self.preview_step = gp('preview_step')
        self.kappa_threshold = gp('kappa_threshold')
        self.kappa_brake_gain = gp('kappa_brake_gain')
        self.max_brake = gp('max_brake')

        # --- State ---
        self._left = []     # [(x, y, z), ...] — left cones
        self._right = []    # [(x, y, z), ...] — right cones
        self._last_stamp = None
        self._prev_steering = 0.0

        # --- Publishers ---
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.debug_pub = self.create_publisher(MarkerArray, '/reactive_nav/debug', 10)

        # --- Subscriber ---
        self.create_subscription(
            Cone3DArray,
            '/cones',
            self._cone_array_cb,
            10
        )

        # --- Control loop ---
        self.create_timer(0.02, self._control_loop)

        # --- Live parameter tuning ---
        self.add_on_set_parameters_callback(self._params_cb)

        self.get_logger().info(
            f'Reactive Nav (Delaunay) started — '
            f'lookahead={self.lookahead_dist}m, '
            f'gas=[{self.min_gas:.3f}, {self.max_gas:.3f}], '
            f'wide_corridor={self.wide_corridor}m'
        )

    # ── Parameters ──────────────────────────────────────────────────────────

    def _params_cb(self, params):
        """Live parameter tuning callback."""
        for p in params:
            if p.name == 'wheelbase':
                self.wheelbase = p.value
            elif p.name == 'lookahead_dist':
                self.lookahead_dist = p.value
            elif p.name == 'max_gas':
                self.max_gas = p.value
            elif p.name == 'min_gas':
                self.min_gas = p.value
            elif p.name == 'wide_corridor':
                self.wide_corridor = p.value
            elif p.name == 'max_steering':
                self.max_steering = p.value
            elif p.name == 'steering_alpha':
                self.steering_alpha = p.value
            elif p.name == 'max_cone_range':
                self.max_cone_range = p.value
            elif p.name == 'boundary_clearance':
                self.boundary_clearance = p.value
            elif p.name == 'preview_step':
                self.preview_step = p.value
            elif p.name == 'kappa_threshold':
                self.kappa_threshold = p.value
            elif p.name == 'kappa_brake_gain':
                self.kappa_brake_gain = p.value
            elif p.name == 'max_brake':
                self.max_brake = p.value
        return SetParametersResult(successful=True)

    # ── Subscriber ──────────────────────────────────────────────────────────

    def _cone_array_cb(self, msg):
        """Parse Cone3DArray and classify left/right by color (preserve z)."""
        if not msg.cones:
            return

        left, right = [], []

        for cone in msg.cones:
            x = cone.position.x
            y = cone.position.y
            z = cone.position.z
            dist = math.sqrt(x * x + y * y)

            # Filter: ahead of car, within range, reasonable angle
            if x < -0.5 or dist > self.max_cone_range:
                continue
            if abs(math.atan2(y, x)) > math.radians(85):
                continue

            # Classify by color: blue_cone → left, yellow_cone → right
            if cone.class_name == 'blue_cone':
                left.append((x, y, z))
            elif cone.class_name == 'yellow_cone':
                right.append((x, y, z))

        # Sort each side independently by x (forward distance)
        left.sort(key=lambda p: p[0])
        right.sort(key=lambda p: p[0])

        self._left = left
        self._right = right
        self._last_stamp = self.get_clock().now()

    # ── Delaunay Path Construction ──────────────────────────────────────────

    def _delaunay_midpoints(self):
        """
        Triangulate cones, extract cross-track edges (left↔right), return
        midpoints sorted by x. Also return edge list for debug viz.
        Returns: (midpoints, edges) where midpoints = [(x,y,z), ...] and
        edges = [((x0,y0,z0), (x1,y1,z1)), ...]
        """
        n_left = len(self._left)
        n_right = len(self._right)
        total = n_left + n_right

        # Single-side fallback
        if n_left == 0 and n_right == 0:
            return [], []

        if n_left == 0:
            # Only right cones: offset left by boundary_clearance
            midpoints = [(x, y + self.boundary_clearance, z) for x, y, z in self._right]
            return sorted(midpoints, key=lambda p: p[0]), []

        if n_right == 0:
            # Only left cones: offset right by boundary_clearance
            midpoints = [(x, y - self.boundary_clearance, z) for x, y, z in self._left]
            return sorted(midpoints, key=lambda p: p[0]), []

        # Triangulate all cones (need at least 3)
        if total < 3:
            return [], []

        # Build combined list and 2D projection
        all_cones = self._left + self._right
        pts_2d = np.array([(x, y) for x, y, z in all_cones], dtype=float)

        try:
            tri = Delaunay(pts_2d)
        except Exception as e:
            self.get_logger().warn(f'Delaunay failed: {e}')
            return [], []

        # Extract cross-track edges
        midpoints = []
        edges = []
        seen = set()

        for simplex in tri.simplices:
            for i in range(3):
                j = (i + 1) % 3
                a, b = simplex[i], simplex[j]
                if a > b:
                    a, b = b, a
                edge_key = (a, b)
                if edge_key in seen:
                    continue
                seen.add(edge_key)

                # Check if this is a cross-track edge
                a_is_left = a < n_left
                b_is_left = b < n_left
                if a_is_left != b_is_left:  # one from each side
                    cone_a = all_cones[a]
                    cone_b = all_cones[b]
                    midpoint = tuple((cone_a[k] + cone_b[k]) / 2.0 for k in range(3))
                    midpoints.append(midpoint)
                    edges.append((cone_a, cone_b))

        if not midpoints:
            return [], []

        # Sort by x coordinate
        midpoints.sort(key=lambda p: p[0])
        return midpoints, edges

    # ── Lookahead and Curvature ─────────────────────────────────────────────

    def _find_lookahead(self, midpoints, target_dist):
        """
        Walk midpoints by 2D arc length until ≥ target_dist.
        Interpolate between bracketing points. Return (x, y, z).
        If path is shorter, return last point.
        """
        if not midpoints:
            return None

        accumulated = 0.0
        for i in range(len(midpoints) - 1):
            p0 = midpoints[i]
            p1 = midpoints[i + 1]
            seg_len = math.sqrt((p1[0] - p0[0]) ** 2 + (p1[1] - p0[1]) ** 2)
            if accumulated + seg_len >= target_dist:
                # Interpolate
                t = (target_dist - accumulated) / (seg_len + 1e-9)
                t = max(0.0, min(1.0, t))
                return tuple(p0[k] + t * (p1[k] - p0[k]) for k in range(3))
            accumulated += seg_len

        return midpoints[-1]

    def _path_kappa(self, midpoints):
        """
        Sample path at preview_step, 2×preview_step, 3×preview_step.
        Compute Menger curvature from the 3 points. Return 0.0 if fewer than 3.
        """
        pts = []
        for k in range(1, 4):
            pt = self._find_lookahead(midpoints, k * self.preview_step)
            if pt is not None:
                pts.append((pt[0], pt[1]))  # Only use x, y for curvature
            else:
                break

        if len(pts) < 3:
            return 0.0

        p0, p1, p2 = pts[0], pts[1], pts[2]
        a = math.sqrt((p1[0] - p0[0]) ** 2 + (p1[1] - p0[1]) ** 2)
        b = math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)
        c = math.sqrt((p0[0] - p2[0]) ** 2 + (p0[1] - p2[1]) ** 2)

        if a < 1e-6 or b < 1e-6 or c < 1e-6:
            return 0.0

        area2 = abs((p1[0] - p0[0]) * (p2[1] - p0[1]) - (p2[0] - p0[0]) * (p1[1] - p0[1]))
        denom = a * b * c
        return area2 / denom if denom > 1e-6 else 0.0

    # ── Control Loop ────────────────────────────────────────────────────────

    def _control_loop(self):
        """50 Hz control loop: Delaunay midpoints + pure pursuit + curvature brake."""

        midpoints, edges = self._delaunay_midpoints()

        if not midpoints:
            # No data or stale: hold steering, brake to stop
            cmd = VehicleControl()
            cmd.use_vc = True
            cmd.selector_ctrl = 1
            cmd.gas = 0.0
            cmd.brake = 1.0
            cmd.steer_ang = self._prev_steering
            self.cmd_pub.publish(cmd)
            self._publish_debug(None, [], [])
            return

        # Lookahead target
        target = self._find_lookahead(midpoints, self.lookahead_dist)
        if target is None:
            cmd = VehicleControl()
            cmd.use_vc = True
            cmd.selector_ctrl = 1
            cmd.gas = 0.0
            cmd.brake = 1.0
            cmd.steer_ang = self._prev_steering
            self.cmd_pub.publish(cmd)
            self._publish_debug(None, [], [])
            return

        lx, ly = target[0], target[1]

        # Pure pursuit steering
        L = math.sqrt(lx * lx + ly * ly)
        if L > 0.5:
            curvature = (2.0 * ly) / (L * L)
            steering = math.atan(curvature * self.wheelbase)
        else:
            steering = 0.0

        # Low-pass filter
        steering = self.steering_alpha * steering + (1.0 - self.steering_alpha) * self._prev_steering
        steering = float(np.clip(steering, -self.max_steering, self.max_steering))
        self._prev_steering = steering

        # Curvature-based braking
        kappa = self._path_kappa(midpoints)
        brake = float(np.clip(
            self.kappa_brake_gain * max(0.0, kappa - self.kappa_threshold),
            0.0,
            self.max_brake
        ))

        # Speed control: brake takes priority
        if brake > 0.0:
            gas = 0.0
        else:
            # Throttle by mean cross-track edge length (proxy for corridor width)
            if edges:
                edge_lens = [math.sqrt((e[1][0] - e[0][0]) ** 2 + (e[1][1] - e[0][1]) ** 2) for e in edges]
                mean_edge_len = np.mean(edge_lens)
            else:
                mean_edge_len = self.wide_corridor

            gas = self.min_gas + (self.max_gas - self.min_gas) * min(mean_edge_len, self.wide_corridor) / self.wide_corridor

        gas = float(np.clip(gas, self.min_gas, self.max_gas))

        cmd = VehicleControl()
        cmd.use_vc = True
        cmd.selector_ctrl = 1
        cmd.gas = gas
        cmd.brake = brake
        cmd.steer_ang = steering
        self.cmd_pub.publish(cmd)

        # Debug viz and logging
        self._publish_debug(target, midpoints, edges)

        if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:
            self.get_logger().info(
                f'steer={math.degrees(steering):6.1f}° gas={gas:.3f} brake={brake:.2f} '
                f'κ={kappa:.3f} n_L={len(self._left):2d} n_R={len(self._right):2d} '
                f'n_edge={len(edges):2d}'
            )

    def _publish_debug(self, target, midpoints, edges):
        """Publish debug markers: cones, Delaunay edges, path, target."""
        out = MarkerArray()
        now = self.get_clock().now().to_msg()
        frame_id = 'Obj_F'

        # DELETEALL
        delete_all = Marker()
        delete_all.action = Marker.DELETEALL
        out.markers.append(delete_all)

        # Individual left cones (blue spheres)
        for i, (x, y, z) in enumerate(self._left):
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'cones', i
            m.type = Marker.SPHERE
            m.action = Marker.ADD
            m.pose.position.x = float(x)
            m.pose.position.y = float(y)
            m.pose.position.z = float(z)
            m.pose.orientation.w = 1.0
            m.scale.x = m.scale.y = m.scale.z = 0.3
            m.color.r, m.color.g, m.color.b = 0.0, 0.3, 1.0
            m.color.a = 0.7
            out.markers.append(m)

        # Individual right cones (yellow spheres)
        for i, (x, y, z) in enumerate(self._right):
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'cones', len(self._left) + i
            m.type = Marker.SPHERE
            m.action = Marker.ADD
            m.pose.position.x = float(x)
            m.pose.position.y = float(y)
            m.pose.position.z = float(z)
            m.pose.orientation.w = 1.0
            m.scale.x = m.scale.y = m.scale.z = 0.3
            m.color.r, m.color.g, m.color.b = 1.0, 1.0, 0.0
            m.color.a = 0.7
            out.markers.append(m)

        # Delaunay cross-track edges (white lines)
        if edges:
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'delaunay', 0
            m.type = Marker.LINE_LIST
            m.action = Marker.ADD
            m.scale.x = 0.05
            m.color.r = m.color.g = m.color.b = m.color.a = 1.0
            for e0, e1 in edges:
                for e in [e0, e1]:
                    p = Point()
                    p.x, p.y, p.z = float(e[0]), float(e[1]), float(e[2])
                    m.points.append(p)
            out.markers.append(m)

        # Path waypoints as a line strip (green)
        if midpoints:
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'path', 0
            m.type = Marker.LINE_STRIP
            m.action = Marker.ADD
            m.scale.x = 0.15
            m.color.r, m.color.g, m.color.b = 0.0, 1.0, 0.0
            m.color.a = 1.0
            for x, y, z in midpoints:
                p = Point()
                p.x, p.y, p.z = float(x), float(y), float(z)
                m.points.append(p)
            out.markers.append(m)

        # Lookahead target (green sphere)
        if target is not None:
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'target', 0
            m.type = Marker.SPHERE
            m.action = Marker.ADD
            m.pose.position.x = float(target[0])
            m.pose.position.y = float(target[1])
            m.pose.position.z = float(target[2])
            m.pose.orientation.w = 1.0
            m.scale.x = m.scale.y = m.scale.z = 0.5
            m.color.r, m.color.g, m.color.b = 0.0, 1.0, 0.0
            m.color.a = 1.0
            out.markers.append(m)

            # Pursuit arrow (yellow)
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'arrow', 0
            m.type = Marker.ARROW
            m.action = Marker.ADD
            m.scale.x = 0.2
            m.scale.y = 0.3
            m.scale.z = 0.2
            m.color.r, m.color.g = 1.0, 1.0
            m.color.b, m.color.a = 0.0, 1.0
            p_start = Point()
            p_start.x = p_start.y = p_start.z = 0.0
            p_end = Point()
            p_end.x = float(target[0])
            p_end.y = float(target[1])
            p_end.z = 0.0
            m.points = [p_start, p_end]
            out.markers.append(m)

            # Status text
            m = Marker()
            m.header.frame_id = frame_id
            m.header.stamp = now
            m.ns, m.id = 'status', 0
            m.type = Marker.TEXT_VIEW_FACING
            m.action = Marker.ADD
            m.pose.position.z = 0.5
            m.pose.orientation.w = 1.0
            m.scale.z = 0.3
            m.color.r = m.color.g = m.color.b = m.color.a = 1.0
            m.text = f'Delaunay: {len(edges)} edges'
            out.markers.append(m)

        self.debug_pub.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = ReactiveNav()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        stop = VehicleControl()
        stop.use_vc = True
        stop.selector_ctrl = 1
        stop.brake = 1.0
        node.cmd_pub.publish(stop)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
