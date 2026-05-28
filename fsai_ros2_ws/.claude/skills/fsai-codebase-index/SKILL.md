---
name: fsai-codebase-index
description: Index of FS-AI autonomous vehicle codebase structure and file locations
license: MIT
compatibility: opencode
metadata:
  audience: developers
  workflow: codebase-navigation
---

# FS-AI Codebase Index

## Project Overview

**FS-AI** is an autonomous racing vehicle for IMechE Formula Student competitions.

## Directory Index

Where different parts of the system live and what they do:

| Directory | Purpose |
|-----------|---------|
| `fsai_main/` | Core ROS2 workspace containing the perception pipeline (detection, fusion, localization) |
| `fsaifork/` | Development fork containing navigation algorithms (path planning, pure pursuit) |
| `FS-AI_API/` | Low-level CAN bus vehicle communication library (C implementation) |
| `FS-AI_IMechE_ADS-DV_HiL/` | CarMaker-based Hardware-in-the-Loop simulation environment |
| `FS-AI_ADS-DV_Documentation/` | Official vehicle specifications and safety procedures (20+ documents) |
| `FS-AI_Compute/` | In-vehicle compute platform specifications and installation guides |
| `FS-AI_ADS-DV_CAD/` | Complete vehicle CAD models (Fusion 360 and STEP formats) |
| `fsai-official/` | Meta-repository aggregating all official implementations as submodules |

## Key Files & Their Purposes

### Perception Pipeline (fsai_main)
- **Camera Detection** → `fsai_main/fsai_ros2_ws/src/perception/camera_detector.py`
  - YOLO v8 cone detection from RGB camera feed
  
- **LiDAR Detection** → `fsai_main/fsai_ros2_ws/src/perception/lidar_detector.py`
  - DBSCAN clustering for 3D point cloud processing
  
- **Sensor Fusion** → `fsai_main/fsai_ros2_ws/src/perception/localizer_3d.py`
  - Late fusion algorithm combining camera and LiDAR detections
  
- **Message Definitions** → `fsai_main/fsai_ros2_ws/src/fsai_interfaces/msg/`
  - `Cone3D.msg` - Single cone detection
  - `Cone3DArray.msg` - Array of cones
  - `VehicleControl.msg` - Vehicle command interface

### Vehicle Control (FS-AI_API)
- **CAN Interface** → `FS-AI_API/src/`
  - Low-level vehicle communication via CAN bus
  - Console tools and testing utilities

### Simulation (FS-AI_IMechE_ADS-DV_HiL)
- **CarMaker Bridge** → `FS-AI_IMechE_ADS-DV_HiL/`
  - Hardware-in-the-loop simulation integration
  - Vehicle dynamics modeling
  - Sensor simulation (LiDAR, camera)
  - ROS2 and CAN connectivity

### Navigation (fsaifork)
- **Path Planning** → `fsaifork/.../path_planning/`
  - Navigation algorithms and trajectory generation
  
- **Pure Pursuit** → `fsaifork/.../pure_pursuit.py`
  - Pure pursuit path tracking algorithm

## Common Tasks Quick Reference

| Task | Location |
|------|----------|
| Modify camera detection algorithm | `fsai_main/` perception pipeline |
| Add or modify CAN vehicle commands | `FS-AI_API/` |
| Test in simulation environment | `FS-AI_IMechE_ADS-DV_HiL/` |
| Work on navigation/path planning | `fsaifork/` |
| Add new sensor | `fsai_main/` perception pipeline + simulation setup |
| Update vehicle specifications | `FS-AI_ADS-DV_Documentation/` or `FS-AI_ADS-DV_CAD/` |

## Architecture Layer Map

The system is organized in layers:

1. **Sensors** → Hardware sensors and simulation (CarMaker)
2. **Perception** → `fsai_main/` (detection + fusion)
3. **Planning** → `fsaifork/` (navigation + path planning)
4. **Control** → `FS-AI_API/` (CAN interface to vehicle)

## Quick Navigation

- **For perception work**: Start in `fsai_main/fsai_ros2_ws/src/perception/`
- **For vehicle control work**: Start in `FS-AI_API/src/`
- **For simulation testing**: Start in `FS-AI_IMechE_ADS-DV_HiL/`
- **For navigation/planning work**: Start in `fsaifork/`
- **For hardware setup**: See `FS-AI_Compute/`
- **For CAD/mechanical**: See `FS-AI_ADS-DV_CAD/`
