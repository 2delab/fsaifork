from setuptools import find_packages, setup
import os
import sys
from glob import glob
import shutil

package_name = 'fsai_perception'

# Helper to pull in external configs for build
def sync_config_files():
    """Copy configs from src/perception/config to package config dir"""
    base_dir = os.path.dirname(os.path.abspath(__file__))
    dest_dir = os.path.join(base_dir, 'config')
    legacy_source_dir = os.path.join(base_dir, '..', 'config')
    files_to_sync = [
        'camera_intrinsics_video.npz',
        'camera_intrinsics_carmaker.npz',
        'extrinsics_carmaker.yaml',
        'camera_mounting_carmaker.yaml',
        'carmaker.rviz',
    ]
    
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)
        
    for f in files_to_sync:
        dst = os.path.join(dest_dir, f)
        # Prefer the package-local config when it already exists.
        if os.path.exists(dst):
            continue

        src = os.path.join(legacy_source_dir, f)
        if not os.path.exists(src):
            sys.stderr.write(f'setup.py: Warning: {src} not found, skipping\n')
            continue

        # If a symlink exists (from a previous failed attempt), remove it first.
        if os.path.islink(dst):
            os.unlink(dst)
        shutil.copy2(src, dst)

sync_config_files()

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*')),
        (os.path.join('share', package_name, 'meshes', 'cones'), glob('meshes/cones/*')),
        (os.path.join('share', package_name, 'meshes', 'car'),   glob('meshes/car/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mdxfsai',
    maintainer_email='shuaibuoluwatunmise@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'cone_visualizer = fsai_perception.cone_visualizer:main',
        ],
    },
)
