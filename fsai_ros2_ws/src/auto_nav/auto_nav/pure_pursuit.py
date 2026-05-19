#!/usr/bin/env python3
"""
Pure Pursuit Autonomous Controller
===================================
Uses Pure Pursuit algorithm with 15m lookahead for smooth path following.
Subscribes to /carmaker/ObjectList (ground truth cones)
Publishes to /carmaker/VehicleControl

Pure Pursuit Algorithm:
1. Find blue/yellow cone pairs at lookahead distance (15m)
2. Calculate midpoint between cone pair
3. Calculate curvature to reach lookahead point
4. Convert curvature to steering angle using vehicle wheelbase

Usage:
    ros2 run auto_nav pure_pursuit
    ros2 run auto_nav pure_pursuit --ros-args -p lookahead_distance:=20.0 -p constant_gas:=0.4
"""

import rclpy
from rclpy.node import Node
import math

from visualization_msgs.msg import MarkerArray, Marker
from vehiclecontrol_msgs.msg import VehicleControl
from geometry_msgs.msg import Point


class PurePursuitController(Node):
    def __init__(self):
        super().__init__('pure_pursuit_controller')
        
        # ══════════════════════════════════════════════════════════════════════
        # Parameters
        # ══════════════════════════════════════════════════════════════════════
        self.declare_parameter('lookahead_distance', 15.0)   # meters (15m default)
        self.declare_parameter('constant_gas', 0.3)          # 30% throttle
        self.declare_parameter('max_steering', 0.6)          # ±34° (safe limit)
        self.declare_parameter('wheelbase', 1.53)            # meters (FS car wheelbase)
        self.declare_parameter('steering_alpha', 0.3)        # Smoothing filter (0-1)
        self.declare_parameter('min_lookahead', 3.0)         # Minimum lookahead distance
        
        self.lookahead_distance = self.get_parameter('lookahead_distance').get_parameter_value().double_value
        self.constant_gas = self.get_parameter('constant_gas').get_parameter_value().double_value
        self.max_steering = self.get_parameter('max_steering').get_parameter_value().double_value
        self.wheelbase = self.get_parameter('wheelbase').get_parameter_value().double_value
        self.steering_alpha = self.get_parameter('steering_alpha').get_parameter_value().double_value
        self.min_lookahead = self.get_parameter('min_lookahead').get_parameter_value().double_value
        
        # ══════════════════════════════════════════════════════════════════════
        # State Variables
        # ══════════════════════════════════════════════════════════════════════
        self.blue_cones = []        # Left boundary cones (x, y)
        self.yellow_cones = []      # Right boundary cones (x, y)
        self.target_x = 15.0        # Target point X (ahead)
        self.target_y = 0.0         # Target point Y (centered)
        self.prev_steering = 0.0    # Previous steering for smoothing
        
        # ══════════════════════════════════════════════════════════════════════
        # ROS2 Setup
        # ══════════════════════════════════════════════════════════════════════
        
        # Subscribe to ObjectList (ground truth cones)
        self.create_subscription(
            MarkerArray,
            '/carmaker/ObjectList',
            self.objectlist_callback,
            10
        )
        
        # Publish VehicleControl commands
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        
        # Publish target visualization (for RViz debugging)
        self.target_viz_pub = self.create_publisher(Marker, '/pure_pursuit/target', 10)
        
        # Control loop timer (50 Hz)
        self.create_timer(0.02, self.control_loop)
        
        # ══════════════════════════════════════════════════════════════════════
        # Startup Info
        # ══════════════════════════════════════════════════════════════════════
        self.get_logger().info('═' * 60)
        self.get_logger().info('Pure Pursuit Controller Started')
        self.get_logger().info('═' * 60)
        self.get_logger().info(f'  Lookahead Distance: {self.lookahead_distance:.1f} m')
        self.get_logger().info(f'  Constant Gas: {self.constant_gas * 100:.0f}%')
        self.get_logger().info(f'  Max Steering: ±{math.degrees(self.max_steering):.1f}°')
        self.get_logger().info(f'  Wheelbase: {self.wheelbase:.2f} m')
        self.get_logger().info(f'  Steering Smoothing: {self.steering_alpha:.2f}')
        self.get_logger().info('═' * 60)
    
    # ══════════════════════════════════════════════════════════════════════════
    # Cone Detection & Path Planning
    # ══════════════════════════════════════════════════════════════════════════
    
    def objectlist_callback(self, msg):
        """Parse ObjectList and extract blue/yellow cone positions"""
        blue_cones = []
        yellow_cones = []
        
        for marker in msg.markers:
            x = marker.pose.position.x
            y = marker.pose.position.y
            
            # Skip cones behind the vehicle
            if x < 0:
                continue
            
            # Extract RGB color
            r = marker.color.r
            g = marker.color.g
            b = marker.color.b
            
            # Classify cone by color (from CMNode_ROS2_HelloCM.cpp)
            # Blue (Left boundary): RGB = (0.0, 0.3, 1.0)
            if b > 0.7 and r < 0.5:
                blue_cones.append((x, y))
            
            # Yellow (Right boundary): RGB = (1.0, 1.0, 0.0)
            elif r > 0.7 and g > 0.7 and b < 0.5:
                yellow_cones.append((x, y))
        
        # Update cone lists
        self.blue_cones = blue_cones
        self.yellow_cones = yellow_cones
        
        # Calculate target point using Pure Pursuit lookahead
        self.calculate_target_point()
    
    def calculate_target_point(self):
        """Find cone pair at lookahead distance and calculate midpoint"""
        if not self.blue_cones or not self.yellow_cones:
            # No cones detected - keep previous target
            return
        
        # Find cones at lookahead distance
        blue_target = self.find_lookahead_cone(self.blue_cones, self.lookahead_distance)
        yellow_target = self.find_lookahead_cone(self.yellow_cones, self.lookahead_distance)
        
        if blue_target and yellow_target:
            # Calculate midpoint between blue and yellow cone at lookahead
            self.target_x = (blue_target[0] + yellow_target[0]) / 2.0
            self.target_y = (blue_target[1] + yellow_target[1]) / 2.0
            
            # Log occasionally for debugging
            if self.get_clock().now().nanoseconds % 1_000_000_000 < 20_000_000:  # ~Every 1 second
                distance_to_target = math.sqrt(self.target_x**2 + self.target_y**2)
                self.get_logger().info(
                    f'Target: ({self.target_x:.2f}, {self.target_y:.2f}) @ {distance_to_target:.2f}m | '
                    f'Blue: {len(self.blue_cones)} | Yellow: {len(self.yellow_cones)}'
                )
        else:
            # Fallback: use closest cones with reduced lookahead
            self.fallback_target_calculation()
    
    def find_lookahead_cone(self, cones, target_distance):
        """Find cone closest to the lookahead distance"""
        if not cones:
            return None
        
        # Calculate distance to each cone
        distances = [(c, math.sqrt(c[0]**2 + c[1]**2)) for c in cones]
        
        # Find cone closest to target_distance
        # Filter cones that are at least at minimum lookahead
        valid_cones = [(c, d) for c, d in distances if d >= self.min_lookahead]
        
        if not valid_cones:
            # No cones at minimum lookahead, use closest available
            return min(distances, key=lambda x: x[1])[0]
        
        # Find cone closest to target lookahead distance
        return min(valid_cones, key=lambda x: abs(x[1] - target_distance))[0]
    
    def fallback_target_calculation(self):
        """Fallback when no cones found at lookahead distance"""
        # Use closest cones if available
        if self.blue_cones and self.yellow_cones:
            closest_blue = min(self.blue_cones, key=lambda c: c[0]**2 + c[1]**2)
            closest_yellow = min(self.yellow_cones, key=lambda c: c[0]**2 + c[1]**2)
            
            self.target_x = (closest_blue[0] + closest_yellow[0]) / 2.0
            self.target_y = (closest_blue[1] + closest_yellow[1]) / 2.0
            
            self.get_logger().warn('Using fallback: closest cones', throttle_duration_sec=2.0)
    
    # ══════════════════════════════════════════════════════════════════════════
    # Pure Pursuit Steering Control
    # ══════════════════════════════════════════════════════════════════════════
    
    def control_loop(self):
        """Calculate steering using Pure Pursuit and publish VehicleControl at 50 Hz"""
        
        # Calculate distance to target (lookahead point)
        L = math.sqrt(self.target_x**2 + self.target_y**2)
        
        # Pure Pursuit formula:
        # Curvature κ = 2 * y / L²
        # Steering angle δ = atan(κ * wheelbase)
        # Where:
        #   y = lateral offset to target point
        #   L = distance to target point
        #   wheelbase = distance between front and rear axles
        
        if L > 0.5:  # Avoid division by zero
            # Calculate curvature to reach lookahead point
            curvature = (2.0 * self.target_y) / (L * L)
            
            # Convert curvature to steering angle using Ackermann steering
            steering_angle = math.atan(curvature * self.wheelbase)
        else:
            # Too close to target or no target - go straight
            steering_angle = 0.0
        
        # Apply exponential smoothing filter to reduce oscillations
        steering_angle = (self.steering_alpha * steering_angle + 
                         (1.0 - self.steering_alpha) * self.prev_steering)
        
        # Clamp steering to safe limits
        steering_angle = max(-self.max_steering, min(self.max_steering, steering_angle))
        
        # Store for next iteration
        self.prev_steering = steering_angle
        
        # Create VehicleControl message
        msg = VehicleControl()
        msg.use_vc = True                   # CRITICAL: Enable vehicle control
        msg.selector_ctrl = 1               # Drive gear
        msg.gas = self.constant_gas         # Constant throttle
        msg.brake = 0.0                     # No brake
        msg.steer_ang = steering_angle      # Pure Pursuit steering angle (rad)
        msg.steer_ang_vel = 0.0             # Not used
        msg.steer_ang_acc = 0.0             # Not used
        
        # Publish command
        self.cmd_pub.publish(msg)
        
        # Publish target visualization for RViz
        self.publish_target_visualization()
    
    def publish_target_visualization(self):
        """Publish target point as marker for RViz debugging"""
        marker = Marker()
        marker.header.frame_id = "OB00"  # ObjectList frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "pure_pursuit"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        
        # Set target position
        marker.pose.position.x = self.target_x
        marker.pose.position.y = self.target_y
        marker.pose.position.z = 0.0
        marker.pose.orientation.w = 1.0
        
        # Green sphere
        marker.scale.x = 0.5
        marker.scale.y = 0.5
        marker.scale.z = 0.5
        marker.color.r = 0.0
        marker.color.g = 1.0
        marker.color.b = 0.0
        marker.color.a = 1.0
        
        marker.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        
        self.target_viz_pub.publish(marker)


def main(args=None):
    rclpy.init(args=args)
    node = PurePursuitController()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down Pure Pursuit Controller...')
    finally:
        # Stop the car safely
        stop_msg = VehicleControl()
        stop_msg.use_vc = True
        stop_msg.selector_ctrl = 1
        stop_msg.gas = 0.0
        stop_msg.brake = 1.0
        stop_msg.steer_ang = 0.0
        stop_msg.steer_ang_vel = 0.0
        stop_msg.steer_ang_acc = 0.0
        node.cmd_pub.publish(stop_msg)
        
        node.get_logger().info('Car stopped. Goodbye!')
        
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
