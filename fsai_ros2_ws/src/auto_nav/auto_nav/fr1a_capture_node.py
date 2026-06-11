#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from tf2_ros import StaticTransformBroadcaster, Buffer, TransformListener
from geometry_msgs.msg import TransformStamped


class Fr1ACaptureNode(Node):
    """
    Captures the car's (CARS00) initial position and publishes it as Fr1A_start.

    Uses tf2_ros.Buffer (C++ backed) to handle large TF messages.
    Looks up Fr1A → CARS00 once at startup and publishes a static frame Fr1A_start there.
    """

    def __init__(self):
        super().__init__('fr1a_capture_node')
        self._static_broadcaster = StaticTransformBroadcaster(self)
        self._tf_buffer = Buffer()
        self._tf_listener = TransformListener(self._tf_buffer, self)

        self._captured = False
        self.create_timer(0.1, self._capture_callback)
        self.get_logger().info('Fr1A capture node started, waiting for CARS00...')

    def _capture_callback(self):
        """Capture CARS00's initial position relative to Fr1A."""
        if self._captured:
            return

        try:
            tf = self._tf_buffer.lookup_transform('Fr1A', 'CARS00', rclpy.time.Time())
        except Exception as e:
            self.get_logger().debug(f'Waiting for CARS00: {e}')
            return

        # Publish static transform: Fr1A → Fr1A_start at CARS00's initial position
        static_transform = TransformStamped()
        static_transform.header.stamp = tf.header.stamp
        static_transform.header.frame_id = 'Fr1A'
        static_transform.child_frame_id = 'Fr1A_start'
        static_transform.transform = tf.transform

        self._static_broadcaster.sendTransform(static_transform)
        self.get_logger().info(
            f'Captured Fr1A_start at ({tf.transform.translation.x:.3f}, '
            f'{tf.transform.translation.y:.3f}, '
            f'{tf.transform.translation.z:.3f})'
        )
        self._captured = True


def main(args=None):
    rclpy.init(args=args)
    node = Fr1ACaptureNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
