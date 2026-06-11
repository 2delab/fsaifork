from launch import LaunchDescription
from launch_ros.actions import Node
from tf2_ros import StaticTransformBroadcaster
from geometry_msgs.msg import TransformStamped


def generate_launch_description():
    # cone_map_tf: publishes cone TFs in world frame
    cone_map_tf_node = Node(
        package='auto_nav',
        executable='cone_map_tf',
        name='cone_map_tf',
        output='screen',
    )

    # tf_map: computes and publishes track path from cone TFs
    tf_map_node = Node(
        package='auto_nav',
        executable='tf_map',
        name='tf_map',
        output='screen',
    )

    # odometry: tracks vehicle position/heading from TF
    odometry_node = Node(
        package='auto_nav',
        executable='odometry',
        name='odometry',
        output='screen',
    )

    return LaunchDescription([
        cone_map_tf_node,
        tf_map_node,
        odometry_node,
    ])
