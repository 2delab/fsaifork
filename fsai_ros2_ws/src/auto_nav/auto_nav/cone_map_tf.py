#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped, Quaternion
from visualization_msgs.msg import MarkerArray
import tf2_ros



class ConeMapTf(Node):
    def __init__(self):
        super().__init__('cone_map_tf')
        self._broadcaster = tf2_ros.StaticTransformBroadcaster(self)
        self._tf_buffer = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buffer, self)
        self._car_published = False
        self.create_subscription(MarkerArray, '/carmaker/ObjectList', self._cb, 10)
        self.get_logger().info('cone_map_tf started')

    def _cb(self, msg):
        if not msg.markers:
            return

        if not self._car_published:
            car_tf = TransformStamped()
            car_tf.header.stamp = self.get_clock().now().to_msg()
            car_tf.header.frame_id = 'CAR500'
            car_tf.child_frame_id = 'car'
            car_tf.transform.rotation.w = 1.0
            self._broadcaster.sendTransform([car_tf])
            self._car_published = True

        src_frame = msg.markers[0].header.frame_id
        stamp = msg.markers[0].header.stamp

        # Try to get the rotation from Fr1A to src_frame so cones have z-up in world
        rotation = Quaternion(w=1.0)
        try:
            tf_lookup = self._tf_buffer.lookup_transform(src_frame, 'Fr1A', stamp, timeout=rclpy.duration.Duration(seconds=0.05))
            rotation = tf_lookup.transform.rotation
        except Exception:
            pass  # Use identity if lookup fails

        stamp_now = self.get_clock().now().to_msg()
        tfs = []
        for m in msg.markers:
            ts = TransformStamped()
            ts.header.stamp = stamp_now
            ts.header.frame_id = src_frame
            ts.child_frame_id = f'cone_{m.id}'
            ts.transform.translation.x = m.pose.position.x
            ts.transform.translation.y = m.pose.position.y
            ts.transform.translation.z = m.pose.position.z
            ts.transform.rotation = rotation
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
