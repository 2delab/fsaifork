"""
Unified Perception Pipeline Launch
Supports multiple sensor sources: mock, zed2, velodyne, carmaker

Usage:
  # Mock (default)
  ros2 launch fsai_perception perception.launch.py source:=mock

  # CarMaker simulation (LiDAR-only cone detection, RViz auto-launched)
  ros2 launch fsai_perception perception.launch.py source:=carmaker

  # Real hardware
  ros2 launch fsai_perception perception.launch.py source:=zed2 use_lidar:=True
"""
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def launch_setup(context, *args, **kwargs):
    source    = LaunchConfiguration('source').perform(context)
    use_lidar = LaunchConfiguration('use_lidar').perform(context)
    visualize = LaunchConfiguration('visualize').perform(context)

    # Package share dirs
    sensors_pkg     = get_package_share_directory('fsai_sensors')
    detectors_pkg   = get_package_share_directory('fsai_cone_detector')
    localizer_pkg   = get_package_share_directory('fsai_localizer_3d')

    perception_pkg  = get_package_share_directory('fsai_perception')
    config_dir      = os.path.join(perception_pkg, 'config')

    # -----------------------------------------------------------------------
    # Pick config files & strategy based on source
    # -----------------------------------------------------------------------
    if source == 'carmaker':
        extrinsics_path = os.path.join(config_dir, 'extrinsics_carmaker.yaml')
        intrinsics_path = os.path.join(config_dir, 'camera_intrinsics_carmaker.npz')
        rviz_config     = os.path.join(config_dir, 'carmaker.rviz')
        camera_source   = 'carmaker'
        lidar_source    = 'carmaker'
        run_rviz        = True
    else:
        extrinsics_path = os.path.join(config_dir, 'extrinsics.yaml')
        intrinsics_path = os.path.join(config_dir, 'camera_intrinsics_video.npz')
        rviz_config     = None
        camera_source   = 'video' if source == 'mock' else source
        lidar_source    = source
        run_camera_detector = True
        run_rviz        = (visualize == 'true')

    actions = []

    # -----------------------------------------------------------------------
    # 1. Sensors (Camera + LiDAR)
    # -----------------------------------------------------------------------
    actions.append(IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(sensors_pkg, 'launch', 'sensors.launch.py')
        ),
        launch_arguments={
            'camera_source': camera_source,
            'lidar_source':  lidar_source,
        }.items()
    ))

    # -----------------------------------------------------------------------
    # 2a. Camera detector (YOLO)
    # -----------------------------------------------------------------------
    actions.append(IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(detectors_pkg, 'launch', 'camera_detector.launch.py')
        )
    ))

    # -----------------------------------------------------------------------
    # 2b. LiDAR detector (DBSCAN clustering)
    # -----------------------------------------------------------------------
    actions.append(IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(detectors_pkg, 'launch', 'lidar_detector.launch.py')
        )
    ))

    # -----------------------------------------------------------------------
    # 3. 3D Localizer (fuses LiDAR + camera, outputs /cones in Fr1A)
    # -----------------------------------------------------------------------
    actions.append(IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(localizer_pkg, 'launch', 'localizer_3d.launch.py')
        ),
        launch_arguments={
            'use_lidar':       use_lidar,
            'extrinsics_file': extrinsics_path,
            'intrinsics_file': intrinsics_path,
        }.items()
    ))



    # -----------------------------------------------------------------------
    # 5. Cone Visualizer: /cones (Cone3DArray) -> /cone_markers (MarkerArray)
    # This is what RViz actually displays — coloured cylinder markers per cone.
    # -----------------------------------------------------------------------
    actions.append(Node(
        package='fsai_perception',
        executable='cone_visualizer',
        name='cone_visualizer',
        output='screen',
    ))

    # -----------------------------------------------------------------------
    # CarMaker only: publish static TF  Fr1A <-> base_link
    # The pipeline outputs cones in 'base_link'. CarMaker's TF tree uses 'Fr1A'
    # as the vehicle base. This alias lets RViz and TF resolve both together.
    # -----------------------------------------------------------------------
    if source == 'carmaker':
        actions.append(Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='fr1a_to_base_link',
            output='screen',
            arguments=['0', '0', '0', '0', '0', '0', 'Fr1A', 'base_link'],
        ))

    # -----------------------------------------------------------------------
    # RViz
    # -----------------------------------------------------------------------
    if run_rviz and rviz_config:
        actions.append(Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=['-d', rviz_config],
        ))

    return actions


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'source', default_value='mock',
            description='Sensor source: mock, zed2, velodyne, carmaker'
        ),
        DeclareLaunchArgument(
            'use_lidar', default_value='True',
            description='Enable LiDAR fusion (always True for carmaker)'
        ),
        DeclareLaunchArgument(
            'visualize', default_value='false',
            description='Launch RViz (always true for carmaker source)'
        ),
        OpaqueFunction(function=launch_setup),
    ])
