
# fsai_main

## Cloning

Clone the full repo first:

```bash
git clone --recurse-submodules https://github.com/MDXFormulaStudents-AI/fsai_main.git
```

## Already cloned?

If you cloned without `--recurse-submodules`, run this to pull in the submodules:

```bash
git submodule update --init
```

## Pulling updates

To pull the latest changes including any submodule updates:

```bash
git pull
git submodule update --init
```


## Enter the Repo Directory

After cloning or updating the repo, switch to the directory containing the repository

```bash
cd fsai_main
```


## Install `vision_msgs`

This workspace expects the ROS package `vision_msgs`.

Assuming your ROS distro is already installed and sourced from `~/.bashrc`, the most convenient command is:

```bash
sudo apt update
sudo apt install ros-${ROS_DISTRO}-vision-msgs
```


## Build the workspace

These instructions assume your base ROS installation is already being sourced from `~/.bashrc`.

If you are starting from the directory that contains the cloned repo:

```bash
cd fsai_ros2_ws
colcon build
```

After the first successful build, add the workspace to your `~/.bashrc` so every new shell picks it up automatically:

```bash
echo "source $(pwd)/install/setup.bash" >> ~/.bashrc
source ~/.bashrc
```


## What should build

A normal build should produce:

- `fsai_interfaces`

## Add ROS Environment To `~/.bashrc`

Finally, to add the recommended ROS networking settings to your `~/.bashrc`, run:

```bash
grep -qxF 'export ROS_DOMAIN_ID=42' ~/.bashrc || echo 'export ROS_DOMAIN_ID=42' >> ~/.bashrc
grep -qxF 'export RMW_IMPLEMENTATION=rmw_fastrtps_cpp' ~/.bashrc || echo 'export RMW_IMPLEMENTATION=rmw_fastrtps_cpp' >> ~/.bashrc
grep -qxF 'unset ROS_AUTOMATIC_DISCOVERY_RANGE' ~/.bashrc || echo 'unset ROS_AUTOMATIC_DISCOVERY_RANGE' >> ~/.bashrc
source ~/.bashrc
```
