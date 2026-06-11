#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion
import tf2_ros
import math


def quaternion_to_yaw(q):
    """Extract yaw (heading) from quaternion, assuming roll=0, pitch=0."""
    return math.atan2(2.0 * (q.w * q.z + q.x * q.y),
                      1.0 - 2.0 * (q.y * q.y + q.z * q.z))


def yaw_to_quaternion(yaw):
    """Create a quaternion with given yaw, roll=0, pitch=0 (z-up)."""
    q = Quaternion()
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    q.x = 0.0
    q.y = 0.0
    q.z = sy
    q.w = cy
    return q


class OdometryNode(Node):
    def __init__(self):
        super().__init__('odometry')
        self._tf_buffer = tf2_ros.Buffer()
        self._tf_listener = tf2_ros.TransformListener(self._tf_buffer, self)
        self.odom_pub = self.create_publisher(Odometry, '/odom', 10)

        self._last_x = None
        self._last_y = None
        self._last_yaw = None
        self._last_time = None
        self._waiting_for_tf = True

        self.create_timer(0.05, self._timer_callback)
        self.get_logger().info('Odometry node started')

    def _timer_callback(self):
        try:
            tf = self._tf_buffer.lookup_transform('Fr1A', 'CAR500', rclpy.time.Time())
            if self._waiting_for_tf:
                self.get_logger().info('Fr1A frame available, odometry tracking started')
                self._waiting_for_tf = False
        except Exception as e:
            if self._waiting_for_tf:
                self.get_logger().warn(f'Waiting for transform: {e}')
            return

        x = tf.transform.translation.x
        y = tf.transform.translation.y
        q = tf.transform.rotation
        yaw = quaternion_to_yaw(q)

        now = self.get_clock().now()

        # Initialize on first call
        if self._last_x is None:
            self._last_x = x
            self._last_y = y
            self._last_yaw = yaw
            self._last_time = now
            return

        # Compute time delta
        dt = (now - self._last_time).nanoseconds / 1e9
        if dt <= 0:
            return

        # Compute 2D velocities
        vx = (x - self._last_x) / dt
        vy = (y - self._last_y) / dt

        # Compute angular velocity (handle yaw wrap-around)
        dyaw = yaw - self._last_yaw
        if dyaw > math.pi:
            dyaw -= 2 * math.pi
        elif dyaw < -math.pi:
            dyaw += 2 * math.pi
        omega = dyaw / dt

        # Build and publish Odometry message
        odom = Odometry()
        odom.header.stamp = tf.header.stamp
        odom.header.frame_id = 'Fr1A'
        odom.child_frame_id = 'CAR500'

        # 2D position (z=0)
        odom.pose.pose.position.x = x
        odom.pose.pose.position.y = y
        odom.pose.pose.position.z = 0.0

        # Orientation: yaw only (z-axis pointing up)
        odom.pose.pose.orientation = yaw_to_quaternion(yaw)

        # 2D velocity
        odom.twist.twist.linear.x = vx
        odom.twist.twist.linear.y = vy
        odom.twist.twist.linear.z = 0.0

        # Angular velocity (z-axis only)
        odom.twist.twist.angular.x = 0.0
        odom.twist.twist.angular.y = 0.0
        odom.twist.twist.angular.z = omega

        self.odom_pub.publish(odom)

        # Update state
        self._last_x = x
        self._last_y = y
        self._last_yaw = yaw
        self._last_time = now


def main(args=None):
    rclpy.init(args=args)
    node = OdometryNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
