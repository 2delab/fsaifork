#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import numpy as np

from visualization_msgs.msg import MarkerArray, Marker
from geometry_msgs.msg import Point, PoseStamped
from nav_msgs.msg import Path


class ArrayMap(Node):
    def __init__(self):
        super().__init__('array_map')

        self.create_subscription(
            MarkerArray,
            '/carmaker/ObjectList',
            self._objectlist_cb,
            10,
        )

        self.map_pub  = self.create_publisher(MarkerArray, '/map/markers', 10)
        self.path_pub = self.create_publisher(Path, '/map/path', 10)
        self.get_logger().info('ArrayMap node started')

    def _objectlist_cb(self, msg):
        if not msg.markers:
            return

        pts = np.array(
            [(m.pose.position.x, m.pose.position.y) for m in msg.markers],
            dtype=float,
        )
        n = len(pts)

        # Find each cone's nearest neighbour.
        nn = np.empty(n, dtype=int)
        for i in range(n):
            d = np.linalg.norm(pts - pts[i], axis=1)
            d[i] = np.inf
            nn[i] = int(np.argmin(d))

        # Build pairs ensuring each cone appears in exactly one pair.
        # Prefer mutual pairs (i→j and j→i) — they are reliable across-track matches.
        # For any cone left unmatched after mutual pairing, pair it with its nearest
        # unmatched cone.
        matched = set()
        pairs = []

        # Pass 1: mutual nearest-neighbour pairs.
        for i in range(n):
            j = nn[i]
            if nn[j] == i and i not in matched and j not in matched:
                pairs.append((i, j))
                matched.add(i)
                matched.add(j)

        # Pass 2: remaining unmatched cones — pair each with nearest unmatched cone.
        unmatched = [i for i in range(n) if i not in matched]
        while len(unmatched) >= 2:
            i = unmatched[0]
            d = np.linalg.norm(pts[unmatched] - pts[i], axis=1)
            d[0] = np.inf
            j = unmatched[int(np.argmin(d))]
            pairs.append((i, j))
            matched.add(i)
            matched.add(j)
            unmatched = [k for k in unmatched if k not in matched]
        midpoints = np.array([(pts[i] + pts[j]) / 2.0 for i, j in pairs])

        # Order pairs by nearest-neighbour chain on their midpoints.
        order = self._nn_order(midpoints)
        pairs = [pairs[k] for k in order]
        midpoints = midpoints[order]

        # Detect bad pairs by two rules:
        #  1. Angle: pair vector roughly parallel to track direction (|cos| > 0.7)
        #     → same-side pair whose midpoint lands on a boundary.
        #  2. Distance: pair distance far outside the median track width
        #     (< 0.3× or > 2.5× median) → jumped to wrong cone or same-side pair
        #     at the start gate where cone counts may be uneven.
        n_pairs = len(pairs)
        track_dirs = self._track_directions(midpoints)

        pair_dists = np.array([np.linalg.norm(pts[j] - pts[i]) for i, j in pairs])
        median_d   = np.median(pair_dists)

        bad = set()
        for k, (i, j) in enumerate(pairs):
            pair_vec = pts[j] - pts[i]
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

        # Assign each good pair's cones to boundary A (left) or B (right) using the
        # local track direction — cross product sign determines which side each cone
        # is on, so neither boundary can cross the centerline.
        a_pts, b_pts = [], []
        for k, (i, j) in enumerate(pairs):
            if k in bad:
                continue
            ci, cj = pts[i], pts[j]
            vec = ci - midpoints[k]
            cross = track_dirs[k][0] * vec[1] - track_dirs[k][1] * vec[0]
            if cross >= 0:
                a_pts.append(ci); b_pts.append(cj)
            else:
                a_pts.append(cj); b_pts.append(ci)

        # Close the loop by appending the first point of each chain to the end.
        a_pts   = np.vstack([a_pts,   a_pts[:1]])
        b_pts   = np.vstack([b_pts,   b_pts[:1]])
        midpoints = np.vstack([midpoints, midpoints[:1]])

        frame = msg.markers[0].header.frame_id
        stamp = self.get_clock().now().to_msg()

        # Publish centreline as nav_msgs/Path (before loop-closure duplicate).
        path = Path()
        path.header.frame_id = frame
        path.header.stamp    = stamp
        for pt in midpoints[:-1]:           # exclude the closing duplicate
            ps = PoseStamped()
            ps.header.frame_id = frame
            ps.header.stamp    = stamp
            ps.pose.position.x = float(pt[0])
            ps.pose.position.y = float(pt[1])
            ps.pose.orientation.w = 1.0
            path.poses.append(ps)
        self.path_pub.publish(path)

        out = MarkerArray()
        out.markers.append(self._line_strip(a_pts,     0, (0.0, 0.3, 1.0), frame, 'boundary_a', stamp))
        out.markers.append(self._line_strip(b_pts,     1, (1.0, 1.0, 0.0), frame, 'boundary_b', stamp))
        out.markers.append(self._line_strip(midpoints, 2, (0.0, 1.0, 0.0), frame, 'centerline',  stamp))
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
        start     = int(np.argmin(np.linalg.norm(pts, axis=1)))
        visited   = [start]
        remaining = list(range(len(pts)))
        remaining.remove(start)
        while remaining:
            last = pts[visited[-1]]
            i    = int(np.argmin(np.linalg.norm(pts[remaining] - last, axis=1)))
            nxt  = remaining[i]
            visited.append(nxt)
            remaining.remove(nxt)
        return visited

    def _line_strip(self, pts, marker_id, rgb, frame_id, ns, stamp):
        m = Marker()
        m.header.frame_id = frame_id
        m.header.stamp    = stamp
        m.ns              = ns
        m.id              = marker_id
        m.type            = Marker.LINE_STRIP
        m.action          = Marker.ADD
        m.scale.x         = 0.15
        m.color.r         = float(rgb[0])
        m.color.g         = float(rgb[1])
        m.color.b         = float(rgb[2])
        m.color.a         = 1.0
        for pt in pts:
            p = Point()
            p.x, p.y, p.z = float(pt[0]), float(pt[1]), 0.0
            m.points.append(p)
        return m


def main(args=None):
    rclpy.init(args=args)
    node = ArrayMap()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
