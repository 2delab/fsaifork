#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from vehiclecontrol_msgs.msg import VehicleControl


class OdomTest(Node):
    def __init__(self):
        super().__init__('odom_test')

        self.create_subscription(Odometry, '/odom', self._odom_cb, 10)
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)

        self._start_x = None
        self._start_y = None
        self._target_distance = 15.0
        self._reached = False

        self.create_timer(0.05, self._control_loop)
        self.get_logger().info(f'OdomTest started: move {self._target_distance}m and stop')

    def _odom_cb(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y

        if self._start_x is None:
            self._start_x = x
            self._start_y = y
            self.get_logger().info(f'Start position: ({x:.2f}, {y:.2f})')
            return

        dx = x - self._start_x
        dy = y - self._start_y
        distance = (dx**2 + dy**2)**0.5

        if distance >= self._target_distance and not self._reached:
            self._reached = True
            self.get_logger().info(f'Target reached! Distance: {distance:.2f}m')

    def _control_loop(self):
        if self._start_x is None or self._reached:
            if not self._reached:
                return
            # Send stop command
            cmd = VehicleControl()
            cmd.use_vc = True
            cmd.selector_ctrl = 1
            cmd.gas = 0.0
            cmd.brake = 0.0
            cmd.steer_ang = 0.0
            cmd.steer_ang_vel = 0.0
            cmd.steer_ang_acc = 0.0
            self.cmd_pub.publish(cmd)
            return

        # Send forward command
        cmd = VehicleControl()
        cmd.use_vc = True
        cmd.selector_ctrl = 1
        cmd.gas = 0.3
        cmd.brake = 0.0
        cmd.steer_ang = 0.0
        cmd.steer_ang_vel = 0.0
        cmd.steer_ang_acc = 0.0
        self.cmd_pub.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = OdomTest()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
