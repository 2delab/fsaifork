from setuptools import find_packages
from setuptools import setup

setup(
    name='vehiclecontrol_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('vehiclecontrol_msgs', 'vehiclecontrol_msgs.*')),
)
