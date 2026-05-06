from setuptools import find_packages
from setuptools import setup

setup(
    name='hellocm_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('hellocm_msgs', 'hellocm_msgs.*')),
)
