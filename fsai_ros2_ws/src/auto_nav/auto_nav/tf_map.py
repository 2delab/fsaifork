#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import numpy as np

from visualization_msgs.msg import MarkerArray, Marker
from geometry_msgs.msg import Point, PoseStamped
from nav_msgs.msg import Path
import tf2_ros


class TfMap(Node):
    def __init__(self):
        super().__init__('tf_map')
        self._tf_buffer = None
        self._tf_listener = None
        self.map_pub = self.create_publisher(MarkerArray, '/map/tf_markers', 10)
        self.path_pub = self.create_publisher(Path, '/map/tf_path', 10)
        self._waiting_for_cones = True
        self.create_timer(1.0, self._timer_callback)
        self.get_logger().info('TfMap node started')

    def _timer_callback(self):
        # Lazy init TF buffer on first use
        if self._tf_buffer is None:
            self._tf_buffer = tf2_ros.Buffer()
            self._tf_listener = tf2_ros.TransformListener(self._tf_buffer, self)

        try:
            frames_str = self._tf_buffer.all_frames_as_string()
        except Exception as e:
            self.get_logger().warn(f'Failed to get frames: {e}', throttle_duration_sec=5.0)
            return

        cone_frames = []
        for line in frames_str.split('\n'):
            parts = line.split()
            if len(parts) >= 2 and 'cone_' in parts[1]:
                cone_frames.append(parts[1])
        if len(cone_frames) < 3:
            if self._waiting_for_cones:
                self.get_logger().warn('Waiting for cone frames (need >=3)...')
                self._waiting_for_cones = False
            return

        if self._waiting_for_cones:
            self.get_logger().info(f'Found {len(cone_frames)} cone frames, computing track...')
            self._waiting_for_cones = False

        # Collect cone positions
        pts = []
        cone_ids = []
        now = rclpy.time.Time()
        for frame in cone_frames:
            try:
                tf = self._tf_buffer.lookup_transform('Fr1A', frame, now, timeout=rclpy.duration.Duration(seconds=0.1))
                x, y, z = tf.transform.translation.x, tf.transform.translation.y, tf.transform.translation.z
                pts.append([x, y, z])
                cone_ids.append(frame)
            except Exception:
                pass

        if len(pts) < 3:
            return

        pts = np.array(pts, dtype=float)
        n = len(pts)
        xy = pts[:, :2]

        # Find each cone's nearest neighbour.
        nn = np.empty(n, dtype=int)
        for i in range(n):
            d = np.linalg.norm(xy - xy[i], axis=1)
            d[i] = np.inf
            nn[i] = int(np.argmin(d))

        # Build pairs ensuring each cone appears in exactly one pair.
        matched = set()
        pairs = []

        # Pass 1: mutual nearest-neighbour pairs.
        for i in range(n):
            j = nn[i]
            if nn[j] == i and i not in matched and j not in matched:
                pairs.append((i, j))
                matched.add(i)
                matched.add(j)

        # Pass 2: remaining unmatched cones.
        unmatched = [i for i in range(n) if i not in matched]
        while len(unmatched) >= 2:
            i = unmatched[0]
            d = np.linalg.norm(xy[unmatched] - xy[i], axis=1)
            d[0] = np.inf
            j = unmatched[int(np.argmin(d))]
            pairs.append((i, j))
            matched.add(i)
            matched.add(j)
            unmatched = [k for k in unmatched if k not in matched]

        if len(pairs) < 2:
            return

        midpoints = np.array([(pts[i] + pts[j]) / 2.0 for i, j in pairs])

        # Order pairs by nearest-neighbour chain on their midpoints.
        order = self._nn_order(midpoints[:, :2])
        pairs = [pairs[k] for k in order]
        midpoints = midpoints[order]

        # Detect bad pairs
        n_pairs = len(pairs)
        track_dirs = self._track_directions(midpoints[:, :2])
        pair_dists = np.array([np.linalg.norm(xy[j] - xy[i]) for i, j in pairs])
        median_d = np.median(pair_dists)

        bad = set()
        for k, (i, j) in enumerate(pairs):
            pair_vec = xy[j] - xy[i]
            norm = pair_dists[k]
            if norm < 0.3 * median_d or norm > 2.5 * median_d:
                bad.add(k)
            elif abs(np.dot(pair_vec / norm, track_dirs[k])) > 0.7:
                bad.add(k)

        for k in sorted(bad):
            prev_ok = next((kk for kk in range(k - 1, -1, -1) if kk not in bad), None)
            next_ok = next((kk for kk in range(k + 1, n_pairs) if kk not in bad), None)
            if prev_ok is not None and next_ok is not None:
                t = (k - prev_ok) / (next_ok - prev_ok)
                midpoints[k] = (1 - t) * midpoints[prev_ok] + t * midpoints[next_ok]
            elif prev_ok is not None:
                midpoints[k] = midpoints[prev_ok]
            elif next_ok is not None:
                midpoints[k] = midpoints[next_ok]

        # Assign cones to boundaries
        a_pts, b_pts = [], []
        for k, (i, j) in enumerate(pairs):
            if k in bad:
                continue
            ci, cj = pts[i], pts[j]
            vec = ci[:2] - midpoints[k, :2]
            cross = track_dirs[k][0] * vec[1] - track_dirs[k][1] * vec[0]
            if cross >= 0:
                a_pts.append(ci)
                b_pts.append(cj)
            else:
                a_pts.append(cj)
                b_pts.append(ci)

        a_pts = np.vstack([a_pts, a_pts[:1]])
        b_pts = np.vstack([b_pts, b_pts[:1]])
        midpoints = np.vstack([midpoints, midpoints[:1]])

        frame = 'Fr1A'
        stamp = self.get_clock().now().to_msg()

        # Publish path
        path = Path()
        path.header.frame_id = frame
        path.header.stamp = stamp
        for pt in midpoints[:-1]:
            ps = PoseStamped()
            ps.header.frame_id = frame
            ps.header.stamp = stamp
            ps.pose.position.x = float(pt[0])
            ps.pose.position.y = float(pt[1])
            ps.pose.position.z = float(pt[2])
            ps.pose.orientation.w = 1.0
            path.poses.append(ps)
        self.path_pub.publish(path)

        # Publish markers
        out = MarkerArray()
        out.markers.append(self._line_strip(a_pts, 0, (0.0, 0.3, 1.0), frame, 'boundary_a', stamp))
        out.markers.append(self._line_strip(b_pts, 1, (1.0, 1.0, 0.0), frame, 'boundary_b', stamp))
        out.markers.append(self._line_strip(midpoints, 2, (0.0, 1.0, 0.0), frame, 'centerline', stamp))
        self.map_pub.publish(out)

    def _track_directions(self, midpoints):
        n = len(midpoints)
        dirs = np.empty((n, 2))
        for k in range(n):
            if k == 0:
                d = midpoints[1] - midpoints[0]
            elif k == n - 1:
                d = midpoints[-1] - midpoints[-2]
            else:
                d = midpoints[k + 1] - midpoints[k - 1]
            norm = np.linalg.norm(d)
            dirs[k] = d / norm if norm > 0 else d
        return dirs

    def _nn_order(self, pts):
        start = int(np.argmin(np.linalg.norm(pts, axis=1)))
        visited = [start]
        remaining = list(range(len(pts)))
        remaining.remove(start)
        while remaining:
            last = pts[visited[-1]]
            i = int(np.argmin(np.linalg.norm(pts[remaining] - last, axis=1)))
            nxt = remaining[i]
            visited.append(nxt)
            remaining.remove(nxt)
        return visited

    def _line_strip(self, pts, marker_id, rgb, frame_id, ns, stamp):
        m = Marker()
        m.header.frame_id = frame_id
        m.header.stamp = stamp
        m.ns = ns
        m.id = marker_id
        m.type = Marker.LINE_STRIP
        m.action = Marker.ADD
        m.scale.x = 0.15
        m.color.r = float(rgb[0])
        m.color.g = float(rgb[1])
        m.color.b = float(rgb[2])
        m.color.a = 1.0
        for pt in pts:
            p = Point()
            p.x, p.y, p.z = float(pt[0]), float(pt[1]), float(pt[2])
            m.points.append(p)
        return m


def main(args=None):
    rclpy.init(args=args)
    node = TfMap()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
