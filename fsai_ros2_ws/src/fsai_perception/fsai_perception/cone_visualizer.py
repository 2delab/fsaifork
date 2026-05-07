#!/usr/bin/env python3
"""
Cone Visualizer Node
Subscribes to /cones (fsai_interfaces/Cone3DArray) → /cone_markers (MarkerArray)
Uses 3D OBJ mesh models (AFS_RaceCar_2024 + traffic cones from FS_autonomous_ros).

Also publishes the car body + 4 wheels on /car_marker at 10 Hz.
"""
import rclpy
from rclpy.node import Node
from fsai_interfaces.msg import Cone3DArray
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import ColorRGBA

# ── Paths ──────────────────────────────────────────────────────────────────────
# Resolve meshes via the ROS package so the markers stay portable across machines
# and workspace locations.
_PKG = 'package://fsai_perception/meshes'

CONE_MESH = {
    'b':         f'{_PKG}/cones/TrafficCone_Small_Blue.obj',
    'y':         f'{_PKG}/cones/TrafficCone_Small_Yellow.obj',
    'o':         f'{_PKG}/cones/TrafficCone_Small_Orange.obj',
    'lo':        f'{_PKG}/cones/TrafficCone_Large_Orange.obj',
    # Keeping original names just in case
    'blue_cone':         f'{_PKG}/cones/TrafficCone_Small_Blue.obj',
    'yellow_cone':       f'{_PKG}/cones/TrafficCone_Small_Yellow.obj',
    'orange_cone':       f'{_PKG}/cones/TrafficCone_Small_Orange.obj',
    'large_orange_cone': f'{_PKG}/cones/TrafficCone_Large_Orange.obj',
}
DEFAULT_CONE_MESH = f'{_PKG}/cones/TrafficCone_Small_Orange.obj'

_CAR_DIR = f'{_PKG}/car'
CAR_BODY_MESH  = f'{_CAR_DIR}/AFS_RaceCar_2024.obj'
CAR_WHEEL_MESH = f'{_CAR_DIR}/AFS_RaceCar_2024_wheel.obj'

# ── Wheel positions in Fr1A frame (from OBJ header) ───────────────────────────
# Wheel.fl/fr/rl/rr: x, y, z from header. OBJ mesh has Translate 0 -0.092 0,
# so subtract 0.092 from y to centre each wheel on its axle in RViz.
_WY_OFFSET = -0.105
_WHEELS = [
    (2.093,  0.476 + _WY_OFFSET, 0.257),   # Front Left
    (2.093, -0.476 + _WY_OFFSET, 0.257),   # Front Right
    (0.557,  0.476 + _WY_OFFSET, 0.257),   # Rear Left
    (0.557, -0.476 + _WY_OFFSET, 0.257),   # Rear Right
]


def _mesh_marker(frame_id, ns, mid, x, y, z, mesh_path, scale=1.0,
                 ox=0.0, oy=0.0, oz=0.0, ow=1.0,
                 lifetime_sec=0) -> Marker:
    m = Marker()
    m.header.frame_id = frame_id
    m.ns     = ns
    m.id     = mid
    m.type   = Marker.MESH_RESOURCE
    m.action = Marker.ADD

    m.pose.position.x = float(x)
    m.pose.position.y = float(y)
    m.pose.position.z = float(z)
    m.pose.orientation.x = ox
    m.pose.orientation.y = oy
    m.pose.orientation.z = oz
    m.pose.orientation.w = ow

    m.scale.x = m.scale.y = m.scale.z = scale
    m.mesh_resource = mesh_path
    m.mesh_use_embedded_materials = True

    if lifetime_sec:
        m.lifetime.sec = lifetime_sec
    return m


class ConeVisualizer(Node):
    def __init__(self):
        super().__init__('cone_visualizer')

        self.declare_parameter('input_topic',  '/cones')
        self.declare_parameter('output_topic', '/cone_markers')
        self.declare_parameter('car_frame',    'Fr1A')

        inp = self.get_parameter('input_topic').value
        out = self.get_parameter('output_topic').value
        self._car_frame = self.get_parameter('car_frame').value

        self.sub = self.create_subscription(Cone3DArray, inp, self.on_cones, 10)
        self.pub = self.create_publisher(MarkerArray, out, 10)

        self.pub_car = self.create_publisher(MarkerArray, '/car_marker', 10)
        self.create_timer(0.1, self._publish_car)

        self.get_logger().info(
            f'Cone visualizer: {inp} → {out} | car mesh → /car_marker'
        )

    # ── Cone markers ───────────────────────────────────────────────────────────

    def on_cones(self, msg: Cone3DArray):
        markers = MarkerArray()

        delete = Marker()
        delete.header = msg.header
        delete.action = Marker.DELETEALL
        markers.markers.append(delete)

        for i, cone in enumerate(msg.cones):
            # Skip unknown-colour cones — noisy LiDAR clusters with no camera match
            if cone.class_name == 'unknown_cone':
                continue
            m = _mesh_marker(
                frame_id     = msg.header.frame_id,
                ns           = 'cones',
                mid          = i,
                x            = cone.position.x,
                y            = cone.position.y,
                z            = cone.position.z,
                mesh_path    = CONE_MESH.get(cone.class_name, DEFAULT_CONE_MESH),
                lifetime_sec = 1,
            )
            # Stamp must match the scan time so RViz looks up the right TF,
            # otherwise stamp=0 → current TF → cones appear displaced by
            # v × pipeline_latency during motion.
            m.header.stamp = msg.header.stamp
            markers.markers.append(m)

            # Text label
            label = Marker()
            label.header = msg.header
            label.ns     = 'cone_labels'
            label.id     = 1000 + i
            label.type   = Marker.TEXT_VIEW_FACING
            label.action = Marker.ADD
            label.pose.position.x = cone.position.x
            label.pose.position.y = cone.position.y
            label.pose.position.z = cone.position.z + 0.45
            label.pose.orientation.w = 1.0
            label.scale.z  = 0.08  # Made font as small as possible while remaining legible
            label.color    = ColorRGBA(r=1.0, g=1.0, b=1.0, a=1.0)
            
            # Use only the first letter (e.g. 'b' for blue, 'y' for yellow) and confidence
            first_letter = cone.class_name[0] if cone.class_name else '?'
            label.text     = f'{first_letter} {cone.confidence:.2f}'
            label.lifetime.sec = 1
            markers.markers.append(label)

        self.pub.publish(markers)

    # ── Car body + wheels ──────────────────────────────────────────────────────

    def _publish_car(self):
        now   = self.get_clock().now().to_msg()
        frame = self._car_frame
        out   = MarkerArray()

        # Car body — OBJ is already in Fr1A frame coordinates (Z-up, X-forward)
        body = _mesh_marker(frame, 'car_body', 0, 0.0, 0.0, 0.0, CAR_BODY_MESH)
        body.header.stamp = now
        out.markers.append(body)

        # Four wheels at their Fr1A positions
        wheel_mesh = CAR_WHEEL_MESH
        for i, (wx, wy, wz) in enumerate(_WHEELS):
            w = _mesh_marker(frame, 'car_wheels', i, wx, wy, wz, wheel_mesh)
            w.header.stamp = now
            out.markers.append(w)

        self.pub_car.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = ConeVisualizer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.try_shutdown()


if __name__ == '__main__':
    main()
