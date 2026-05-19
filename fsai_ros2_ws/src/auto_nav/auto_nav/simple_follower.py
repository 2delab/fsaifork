#!/usr/bin/env python3
"""
Simple Autonomous Cone Follower
================================
Subscribes to /carmaker/ObjectList (ground truth cones)
Finds closest blue/yellow cone pair
Steers towards midpoint at constant speed

Usage:
    ros2 run auto_nav simple_follower
    ros2 run auto_nav simple_follower --ros-args -p constant_gas:=0.5
"""

import rclpy
from rclpy.node import Node
import math

from visualization_msgs.msg import MarkerArray
from vehiclecontrol_msgs.msg import VehicleControl


class SimpleFollower(Node):
    def __init__(self):
        super().__init__('simple_follower')
        
        # Parameters
        self.declare_parameter('constant_gas', 0.3)      # 30% throttle (default)
        self.declare_parameter('max_steering', 0.6)      # ±34° (safe limit)
        self.declare_parameter('steering_gain', 1.0)     # Proportional gain
        
        self.constant_gas = self.get_parameter('constant_gas').get_parameter_value().double_value
        self.max_steering = self.get_parameter('max_steering').get_parameter_value().double_value
        self.steering_gain = self.get_parameter('steering_gain').get_parameter_value().double_value
        
        # Subscribe to ObjectList (ground truth cones)
        self.create_subscription(
            MarkerArray, 
            '/carmaker/ObjectList', 
            self.objectlist_callback, 
            10
        )
        
        # Publish VehicleControl commands
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        
        # Control loop timer (50 Hz)
        self.create_timer(0.02, self.control_loop)
        
        # Target point (midpoint between closest blue/yellow cones)
        self.target_x = 5.0  # Default: 5m ahead
        self.target_y = 0.0  # Default: centered
        
        # Cone tracking
        self.blue_cones = []    # Left boundary
        self.yellow_cones = []  # Right boundary
        
        self.get_logger().info('Simple Follower Node Started')
        self.get_logger().info(f'  Constant Gas: {self.constant_gas * 100:.0f}%')
        self.get_logger().info(f'  Max Steering: ±{math.degrees(self.max_steering):.1f}°')
        self.get_logger().info(f'  Steering Gain: {self.steering_gain}')
        
    def objectlist_callback(self, msg):
        """Parse ObjectList and extract blue/yellow cone positions"""
        blue_cones = []
        yellow_cones = []
        
        for marker in msg.markers:
            x = marker.pose.position.x
            y = marker.pose.position.y
            
            # Extract RGB color
            r = marker.color.r
            g = marker.color.g
            b = marker.color.b
            
            # Classify cone by color (from CMNode_ROS2_HelloCM.cpp)
            # Blue (Left boundary): RGB = (0.0, 0.3, 1.0)
            if b > 0.8 and r < 0.5 and g < 0.5:
                blue_cones.append((x, y))
            
            # Yellow (Right boundary): RGB = (1.0, 1.0, 0.0)
            elif r > 0.8 and g > 0.8 and b < 0.5:
                yellow_cones.append((x, y))
        
        # Update cone lists
        self.blue_cones = blue_cones
        self.yellow_cones = yellow_cones
        
        # Calculate target point (midpoint between closest cones)
        if self.blue_cones and self.yellow_cones:
            # Find closest blue and yellow cones by distance
            closest_blue = min(self.blue_cones, key=lambda c: c[0]**2 + c[1]**2)
            closest_yellow = min(self.yellow_cones, key=lambda c: c[0]**2 + c[1]**2)
            
            # Calculate midpoint
            self.target_x = (closest_blue[0] + closest_yellow[0]) / 2.0
            self.target_y = (closest_blue[1] + closest_yellow[1]) / 2.0
            
            # Log occasionally for debugging
            if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:  # ~Every 1 second
                self.get_logger().info(
                    f'Target: ({self.target_x:.2f}, {self.target_y:.2f}) | '
                    f'Blue: {len(self.blue_cones)} | Yellow: {len(self.yellow_cones)}'
                )
    
    def control_loop(self):
        """Calculate steering and publish VehicleControl at 50 Hz"""
        
        # Calculate steering angle towards target
        # Use atan2 to get angle to target point
        steering_angle = math.atan2(self.target_y, self.target_x) * self.steering_gain
        
        # Clamp steering to safe limits
        steering_angle = max(-self.max_steering, min(self.max_steering, steering_angle))
        
        # Create VehicleControl message
        msg = VehicleControl()
        msg.use_vc = True                   # CRITICAL: Enable vehicle control
        msg.selector_ctrl = 1               # Drive gear
        msg.gas = self.constant_gas         # Constant throttle
        msg.brake = 0.0                     # No brake
        msg.steer_ang = steering_angle      # Calculated steering angle (rad)
        msg.steer_ang_vel = 0.0             # Not used
        msg.steer_ang_acc = 0.0             # Not used
        
        # Publish command
        self.cmd_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = SimpleFollower()
    
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
