#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import math
import numpy as np

from nav_msgs.msg import Path, Odometry
from visualization_msgs.msg import Marker
from vehiclecontrol_msgs.msg import VehicleControl


class PurePursuitController(Node):
    def __init__(self):
        super().__init__('pure_pursuit_controller')

        self.declare_parameter('lookahead_distance', 6.0)
        self.declare_parameter('constant_gas',       0.3)
        self.declare_parameter('max_steering',       0.6)
        self.declare_parameter('wheelbase',          1.53)
        self.declare_parameter('steering_alpha',     0.3)

        self.lookahead_distance = self.get_parameter('lookahead_distance').get_parameter_value().double_value
        self.constant_gas       = self.get_parameter('constant_gas').get_parameter_value().double_value
        self.max_steering       = self.get_parameter('max_steering').get_parameter_value().double_value
        self.wheelbase          = self.get_parameter('wheelbase').get_parameter_value().double_value
        self.steering_alpha     = self.get_parameter('steering_alpha').get_parameter_value().double_value

        self.path_pts    = None   # np.array shape (N, 2) in world frame
        self.car_x       = 0.0
        self.car_y       = 0.0
        self.car_yaw     = 0.0
        self.prev_steering = 0.0

        self.create_subscription(Path,     '/map/path',      self._path_cb,  10)
        self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb,  10)

        self.cmd_pub        = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)
        self.target_viz_pub = self.create_publisher(Marker, '/pure_pursuit/target', 10)

        self.create_timer(0.02, self._control_loop)

        self.get_logger().info(
            f'Pure Pursuit started — lookahead={self.lookahead_distance}m '
            f'gas={self.constant_gas*100:.0f}% wheelbase={self.wheelbase}m'
        )

    def _path_cb(self, msg):
        if not msg.poses:
            return
        self.path_pts = np.array(
            [(p.pose.position.x, p.pose.position.y) for p in msg.poses],
            dtype=float,
        )

    def _odom_cb(self, msg):
        self.car_x = msg.pose.pose.position.x
        self.car_y = msg.pose.pose.position.y
        q = msg.pose.pose.orientation
        self.car_yaw = math.atan2(
            2.0 * (q.w * q.z + q.x * q.y),
            1.0 - 2.0 * (q.y * q.y + q.z * q.z),
        )

    def _find_lookahead_point(self):
        """Return the path point lookahead_distance ahead of the car, or None."""
        pts = self.path_pts
        n   = len(pts)
        car = np.array([self.car_x, self.car_y])

        # Closest path point to car.
        closest = int(np.argmin(np.linalg.norm(pts - car, axis=1)))

        # Walk forward (wrapping) until we reach lookahead distance.
        for offset in range(n):
            idx = (closest + offset) % n
            if np.linalg.norm(pts[idx] - car) >= self.lookahead_distance:
                return pts[idx]

        return pts[(closest + n // 2) % n]

    def _control_loop(self):
        if self.path_pts is None or len(self.path_pts) == 0:
            return

        lp = self._find_lookahead_point()
        if lp is None:
            return

        # Transform lookahead point into vehicle frame.
        dx = lp[0] - self.car_x
        dy = lp[1] - self.car_y
        cos_y, sin_y = math.cos(self.car_yaw), math.sin(self.car_yaw)
        local_x =  dx * cos_y + dy * sin_y
        local_y = -dx * sin_y + dy * cos_y

        # Pure pursuit: κ = 2y / L², δ = atan(κ · wheelbase)
        L = math.sqrt(local_x ** 2 + local_y ** 2)
        if L > 0.5:
            curvature     = (2.0 * local_y) / (L * L)
            steering_angle = math.atan(curvature * self.wheelbase)
        else:
            steering_angle = 0.0

        # Exponential smoothing.
        steering_angle = (self.steering_alpha * steering_angle +
                         (1.0 - self.steering_alpha) * self.prev_steering)
        steering_angle = max(-self.max_steering, min(self.max_steering, steering_angle))
        self.prev_steering = steering_angle

        cmd = VehicleControl()
        cmd.use_vc       = True
        cmd.selector_ctrl = 1
        cmd.gas          = self.constant_gas
        cmd.brake        = 0.0
        cmd.steer_ang    = steering_angle
        self.cmd_pub.publish(cmd)

        self._publish_target(lp)

    def _publish_target(self, lp):
        m = Marker()
        m.header.frame_id = 'Obj_F'
        m.header.stamp    = self.get_clock().now().to_msg()
        m.ns, m.id        = 'pure_pursuit', 0
        m.type            = Marker.SPHERE
        m.action          = Marker.ADD
        m.pose.position.x = float(lp[0])
        m.pose.position.y = float(lp[1])
        m.pose.orientation.w = 1.0
        m.scale.x = m.scale.y = m.scale.z = 0.5
        m.color.g = 1.0
        m.color.a = 1.0
        m.lifetime = rclpy.duration.Duration(seconds=0.1).to_msg()
        self.target_viz_pub.publish(m)


def main(args=None):
    rclpy.init(args=args)
    node = PurePursuitController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        stop = VehicleControl()
        stop.use_vc        = True
        stop.selector_ctrl = 1
        stop.brake         = 1.0
        node.cmd_pub.publish(stop)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
