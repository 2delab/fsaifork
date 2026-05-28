from setuptools import setup

package_name = 'auto_nav'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='FSAI Team',
    maintainer_email='fsai@example.com',
    description='Simple autonomous navigation using ObjectList ground truth',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'simple_follower = auto_nav.simple_follower:main',
            'pure_pursuit = auto_nav.pure_pursuit:main',
            'array_map = auto_nav.array_map:main',
            'adaptive_pursuit = auto_nav.adaptive_pursuit:main',
            'stanley = auto_nav.stanley:main',
            'mpc = auto_nav.mpc:main',
            'lqr = auto_nav.lqr:main',
            'ilqr = auto_nav.ilqr:main',
            'teleop_node = auto_nav.teleop_node:main',
        ],
    },
)
