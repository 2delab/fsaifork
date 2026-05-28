# array_map

ROS2 node that builds a track boundary map from raw cone positions published by CarMaker, without relying on cone colour labels.

## Topics

| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/carmaker/ObjectList` | `visualization_msgs/MarkerArray` |
| Publishes | `/map/markers` | `visualization_msgs/MarkerArray` |

## Published markers

| Namespace | Colour | Content |
|-----------|--------|---------|
| `boundary_a` | Blue | Left boundary |
| `boundary_b` | Yellow | Right boundary |
| `centerline` | Green | Track centreline |

## Algorithm

### 1. Pairing
Each cone is matched to exactly one partner across the track using two passes:

- **Pass 1 — mutual nearest-neighbour**: cone A pairs with cone B only if A is B's nearest neighbour *and* B is A's nearest neighbour. These are reliable across-track pairs.
- **Pass 2 — unmatched remainder**: any cone not claimed in pass 1 is paired with its nearest unmatched cone. Handles uneven cone counts at the start gate.

This always produces exactly `n/2` pairs.

### 2. Ordering
Pairs are ordered into a continuous loop using a nearest-neighbour chain on their midpoints, starting from the midpoint closest to the origin.

### 3. Bad pair detection
After ordering, each pair is validated against two rules. Pairs failing either are flagged as bad:

- **Angle** — pair vector dot local track direction `> 0.7` (pair runs parallel to the track rather than across it — same-side pairing).
- **Distance** — pair distance `< 0.3×` or `> 2.5×` the median pair distance (jumped to wrong cone or same-side corner pairing).

Bad pair midpoints are replaced by linear interpolation from their nearest good neighbours. Bad pairs are excluded from boundary assignment.

### 4. Left / right assignment
For each good pair, the local track direction (central difference of adjacent midpoints) is computed. A cross product of the track direction with the vector from midpoint to each cone determines which side is left (boundary A) and which is right (boundary B). This guarantees neither boundary ever crosses the centreline.

### 5. Loop closure
The first point of each chain is appended to the end so all three line strips form a closed loop.

## Running

```bash
source install/setup.bash
ros2 run auto_nav array_map
```

View in RViz by adding a **MarkerArray** display on `/map/markers`. Set the **Fixed Frame** to match the ObjectList frame (`Obj_F`).
