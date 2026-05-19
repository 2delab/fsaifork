---
name: fsai-architecture
description: FS-AI autonomous vehicle system architecture and data flow
license: MIT
compatibility: opencode
metadata:
  audience: developers
  workflow: architecture-reference
---

# FS-AI System Architecture

## Project Overview

FS-AI is an autonomous racing vehicle system designed for IMechE Formula Student competitions. The system processes multi-sensor inputs to detect track markers (cones) and perform autonomous racing tasks.

## Architecture Overview

The system is organized into 6 layers:

1. **Sensor Data** - Raw input from simulation/hardware
2. **Sensor Processing** - Data transformation and relay
3. **Detection** - Parallel cone detection from camera and LiDAR
4. **Fusion** - Unified cone detection from sensor data
5. **Planning** - Path planning (not implemented)
6. **Control** - Vehicle control (not implemented)

## Data Flow

### Layer 1: Sensor Data

Raw sensor inputs come from CarMaker simulation (Windows PC, IPG CarMaker 14.1.1):

- `/front_camera_rgb/image_raw` - RGB video, 30 fps
- `/front_camera_depth/image_raw` - Depth data, mono16 in cm
- `/carmaker/pointcloud` - LiDAR point cloud, PointCloud v1
- `/carmaker/odom` - Vehicle odometry
- `/carmaker/ObjectList` - Ground truth (visualization only)

Data is transmitted via ROS2 DDS network.

### Layer 2: Sensor Processing

The CarMaker Bridge transforms and relays sensor data:

- `/front_camera_rgb` → `/camera/image_raw` (direct relay)
- `/front_camera_depth` → `/camera/depth` (converts mono16 cm to float32 m)
- `/carmaker/pointcloud` → `/lidar/pointcloud` (PointCloud v1 to v2 conversion)

### Layer 3: Detection

Two parallel detection processes run simultaneously:

**YOLO Camera Detector**
- Input: `/camera/image_raw` (RGB camera feed)
- Output: `/detections` (2D bounding boxes and cone colors)
- Processing rate: ~12.5 Hz
- Produces: 2D bounding boxes, cone colors (yellow/blue/orange), YOLO confidence scores

**DBSCAN LiDAR Detector**
- Input: `/lidar/pointcloud` (3D point cloud)
- Output: `/detections/lidar` (3D cluster positions)
- Processing rate: ~8 Hz
- Produces: 3D cluster positions, confidence scores, point cloud segments

### Layer 4: Fusion

The 3D Localizer combines camera and LiDAR detections using a late fusion approach:

**Algorithm: Project-Match-Assign**
1. Projects each LiDAR detection into the camera image plane
2. Checks if projection lands inside YOLO bounding box (±40px margin)
3. Uses Hungarian assignment to optimally match all detections
4. Assigns YOLO color information to LiDAR 3D position

**Input:**
- `/detections` - YOLO camera detections
- `/detections/lidar` - DBSCAN LiDAR detections

**Output:**
- `/cones` - Cone3DArray (fused detections in Fr1A vehicle frame)
- Processing rate: ~10 Hz

**Quality Metrics:**
- Fused cones: confidence 0.85-0.95, accurate 3D geometry
- LiDAR-only cones: confidence ~0.9, color="unknown_cone"

### Layer 5: Planning

**Status: Not implemented**

Input:
- `/cones` - Detected track markers
- `/carmaker/odom` - Vehicle odometry

Output:
- `/planned_path` - Path trajectory
- `/target_trajectory` - Target waypoints

### Layer 6: Control

**Status: Not implemented**

Input:
- `/planned_path` - Planned trajectory
- `/cones` - Cone detections
- `/carmaker/odom` - Vehicle odometry

Output:
- `/carmaker/VehicleControl` - Vehicle control commands (steering, throttle, brake)

Command rate: 50 Hz (0.02s cycle)

## Coordinate Frames

All cone positions are expressed in the Fr1A (Vehicle Front Axle Reference Frame):

- **Origin:** Front axle center, on ground plane
- **X-axis:** Forward direction (positive toward track)
- **Y-axis:** Left (positive = vehicle left side)
- **Z-axis:** Up (positive upward)

**Published Transforms (from Fr1A):**
- Fr1A → Lidar_F: translation (2.921, 0.0, 0.163) meters
- Fr1A → Obj_F: translation (1.532, 0.0, 0.816) meters
- Fr1A → OB00: object sensor position

## Message Definitions

### Cone3D

Represents a single detected cone:

```
header: Header
  frame_id: "Fr1A"
  stamp: ROS timestamp
position: Point
  x, y, z (metres)
class_name: string ("yellow", "blue", "orange", "unknown_cone")
confidence: float (0.0-1.0)
source: string ("fused", "lidar")
```

### Cone3DArray

Collection of cone detections:

```
header: Header
cones: Cone3D[] (array of cones)
```

### VehicleControl

Vehicle control command interface:

```
use_vc: bool (must be True to enable)
selector_ctrl: int (1 = Drive mode)
gas: float (0.0-1.0, throttle pedal)
brake: float (0.0-1.0, brake pedal)
steer_ang: float (radians, positive = left turn)
steer_ang_vel: float (steering angular velocity, radians/second)
steer_ang_acc: float (steering angular acceleration, radians/second²)
```

## System Components

### Detection Algorithms

**YOLO v8 (Camera)**
- Detects cone bounding boxes in 2D image space
- Classifies cone colors with high reliability
- Produces 2D spatial data only

**DBSCAN (LiDAR)**
- Clusters 3D point cloud into discrete objects
- Produces accurate 3D positions
- No color information

### Fusion Algorithm

**Project-Match-Assign**
- Geometric fusion that combines 2D color information with 3D spatial accuracy
- Projects 3D LiDAR positions into camera image coordinates
- Matches projections with YOLO bounding boxes using geometric overlap
- Hungarian algorithm ensures optimal one-to-one assignments

## Data Pipeline Summary

```
Sensors (CarMaker)
       ↓
Sensor Processing (Bridge)
       ↓
Detection (YOLO + DBSCAN in parallel)
       ↓
Fusion (Project-Match-Assign)
       ↓
Cone3DArray /cones (Fr1A frame)
       ↓
[Planning Layer - Not Implemented]
       ↓
[Control Layer - Not Implemented]
       ↓
VehicleControl Commands
```
