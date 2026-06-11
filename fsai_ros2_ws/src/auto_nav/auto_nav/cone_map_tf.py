#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from visualization_msgs.msg import MarkerArray
import tf2_ros


class ConeMapTf(Node):
    def __init__(self):
        super().__init__('cone_map_tf')
        self._broadcaster = tf2_ros.StaticTransformBroadcaster(self)
        self.create_subscription(MarkerArray, '/carmaker/ObjectList', self._cb, 10)
        self.get_logger().info('cone_map_tf started')

    def _cb(self, msg):
        if not msg.markers:
            return

        src_frame = msg.markers[0].header.frame_id
        stamp = self.get_clock().now().to_msg()

        tfs = []
        for m in msg.markers:
            ts = TransformStamped()
            ts.header.stamp = stamp
            ts.header.frame_id = src_frame
            ts.child_frame_id = f'cone_{m.id}'
            ts.transform.translation.x = m.pose.position.x
            ts.transform.translation.y = m.pose.position.y
            ts.transform.translation.z = m.pose.position.z
            ts.transform.rotation.w = 1.0
            tfs.append(ts)

        self._broadcaster.sendTransform(tfs)


def main(args=None):
    rclpy.init(args=args)
    node = ConeMapTf()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
