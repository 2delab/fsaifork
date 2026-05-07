# Formula Student AI - Perception System (Unified)

This package creates a **unified entry point** for the entire perception pipeline. It launches:
1.  **Sensors** (`fsai_sensors`) - Camera, LiDAR (Mock/Real)
2.  **Detectors** (`fsai_cone_detector`) - YOLOv8, Clustering
3.  **Localizer** (`fsai_localizer_3d`) - Fusion, Extrinsics
4.  **Transformer** (`fsai_frame_transformer`) - Vehicle Frame Output

---

## Quick Start

### Run Everything (Mock Mode)
```bash
source /home/mdxfsai/fsai_ws/install/setup.bash
ros2 launch fsai_perception perception.launch.py source:=mock
```

### Run Everything (Real Hardware)
```bash
ros2 launch fsai_perception perception.launch.py \
    source:=zed2 \
    use_lidar:=True
```

### Run Everything (CarMaker)
```bash
ros2 launch fsai_perception perception.launch.py source:=carmaker
```

---

## Output Verification

To see the final output (Cones relative to Car Center):
```bash
ros2 topic echo /cones --once
```

**Expected Output:**
- **Frame ID:** `base_link`
- **X:** Positive (Forward)
- **Y:** Positive Left / Negative Right
- **Z:** ~0.0 (Ground level relative to axle)

---

## Architecture Flow
Sensor (Camera/LiDAR) -> Detector (2D/3D Cones) -> Localizer (Fused Cones + Extrinsics) -> Transformer (Vehicle Frame) -> **/cones**
