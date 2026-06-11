#!/usr/bin/env python3
"""
Distance Follower Node
======================
Moves the car forward 10 meters using odometry, then stops.

Subscribes to /odom for position tracking
Publishes VehicleControl commands to /carmaker/VehicleControl

Usage:
    ros2 run auto_nav distance_follower
    ros2 run auto_nav distance_follower --ros-args -p target_distance:=20.0
"""

import rclpy
from rclpy.node import Node
import math

from nav_msgs.msg import Odometry
from fsai_interfaces.msg import VehicleControl


class DistanceFollower(Node):
    def __init__(self):
        super().__init__('distance_follower')

        # Parameters
        self.declare_parameter('target_distance', 10.0)    # Distance in meters
        self.declare_parameter('constant_gas', 0.1)        # Throttle (0-1)

        self.target_distance = self.get_parameter('target_distance').get_parameter_value().double_value
        self.constant_gas = self.get_parameter('constant_gas').get_parameter_value().double_value

        # Subscribe to odometry
        self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10
        )

        # Publish VehicleControl commands
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)

        # Control loop timer (50 Hz)
        self.create_timer(0.02, self.control_loop)

        # State tracking
        self.start_x = None
        self.start_y = None
        self.current_x = None
        self.current_y = None
        self.target_reached = False
        self.last_log_distance = -1.0

        self.get_logger().info('Distance Follower Node Started')
        self.get_logger().info(f'  Target Distance: {self.target_distance} m')
        self.get_logger().info(f'  Constant Gas: {self.constant_gas * 100:.0f}%')

    def odom_callback(self, msg):
        """Track current position from odometry"""
        self.current_x = msg.pose.pose.position.x
        self.current_y = msg.pose.pose.position.y

        # Initialize starting position
        if self.start_x is None:
            self.start_x = self.current_x
            self.start_y = self.current_y
            self.get_logger().info(f'Starting position: ({self.start_x:.2f}, {self.start_y:.2f})')

    def control_loop(self):
        """Publish control commands - always move forward unless distance reached"""

        # Create VehicleControl message
        msg = VehicleControl()
        msg.use_vc = True
        msg.selector_ctrl = 1  # Drive gear
        msg.gas = self.constant_gas  # Move forward by default
        msg.brake = 0.0
        msg.steer_ang = 0.0    # Go straight
        msg.steer_ang_vel = 0.0
        msg.steer_ang_acc = 0.0

        # If odometry available, check if we reached target distance
        if self.current_x is not None and self.start_x is not None:
            dx = self.current_x - self.start_x
            dy = self.current_y - self.start_y
            distance = math.sqrt(dx**2 + dy**2)

            if distance >= self.target_distance:
                msg.gas = 0.0
                msg.brake = 1.0  # Apply full brake

                if not self.target_reached:
                    self.get_logger().info(f'Target distance reached: {distance:.2f} m. Stopping.')
                    self.target_reached = True
            else:
                # Log progress at 1m intervals
                if int(distance) > int(self.last_log_distance):
                    self.get_logger().info(f'Distance: {distance:.2f} m / {self.target_distance} m')
                    self.last_log_distance = distance

        # Publish command
        self.cmd_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = DistanceFollower()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        # Stop the car
        stop_msg = VehicleControl()
        stop_msg.use_vc = True
        stop_msg.selector_ctrl = 1
        stop_msg.gas = 0.0
        stop_msg.brake = 1.0
        stop_msg.steer_ang = 0.0
        node.cmd_pub.publish(stop_msg)

        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
