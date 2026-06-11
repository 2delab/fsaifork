from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """
    Launch file that captures the car's initial position as Fr1A_start.

    Publishes a static frame Fr1A_start at CARS00's starting position relative to Fr1A.
    CARS00 (the car) drives away; Fr1A_start stays fixed at the starting point.
    """
    fr1a_capture_node = Node(
        package='auto_nav',
        executable='fr1a_capture_node',
        name='fr1a_capture_node',
        output='screen',
    )

    return LaunchDescription([fr1a_capture_node])
