# auto_nav — Controller Overview

## Architecture

```
CarMaker
  └── /carmaker/ObjectList  ──►  array_map  ──►  /map/path        ──►  controller
  └── /carmaker/odom        ─────────────────────────────────────►  controller
                                            └──►  /map/markers        (RViz)

controller  ──►  /carmaker/VehicleControl  ──►  CarMaker
```

`array_map` runs continuously and publishes the track map. Any controller node can be swapped in/out independently — they all share the same two input topics.

---

## Controller progression

Each node was built to address a specific limitation of the previous one.

| Node | Steers toward | Speed planning | Key limitation fixed |
|------|--------------|----------------|----------------------|
| `simple_follower` | Nearest cone midpoint | None | Baseline only |
| `pure_pursuit` | Lookahead point on path | None | Colour-independent, uses pre-built map |
| `adaptive_pursuit` | Adaptive lookahead point | Preview curvature scan | Speed adapts to upcoming corners |
| `stanley` | Nearest path point (front axle) | Global two-pass profile | Corrects CTE + heading simultaneously; globally optimal speed |
| `mpc` | N-step optimal control | Global two-pass profile | Look-ahead in steering law |
| `lqr` | Nearest path point + feedforward | Global two-pass profile | MPC accuracy at zero runtime cost |
| `ilqr` | N-step optimal (re-linearised) | Global two-pass profile | Accurate gains even at large deviations |

---

## Global two-pass speed profile

First introduced in `stanley`, used by all subsequent nodes. Computed once when `/map/path` arrives:

**Forward pass** — starting from the first point, propagate acceleration limits around the loop. At each corner, cap by `v_lat = sqrt(lat_accel_limit / κ)`. Run twice to close the loop.

**Backward pass** — working backwards, ensure the car is at the right speed *on arrival* at each corner, accounting for braking distance. Run twice to close the loop.

Result: `v_profile[k]` — optimal target speed at every path point. The car accelerates as hard as possible on straights and brakes at the latest safe moment before each corner.

---

## Shared design choices

- **Frame assumption**: `/carmaker/odom` (`odom` → `base_link`) and `/map/path` (`Obj_F`) are treated as the same coordinate frame. CarMaker initialises both from the same world origin.
- **Nearest-point search**: monotonic forward-only window of 10 points to prevent index jumping on straights.
- **Tangent computation**: central difference `pts[k-1] → pts[k+1]` to smooth per-point cone noise.
- **Steering smoothing**: first-order low-pass filter (`steering_alpha`) on all nodes.
- **Emergency stop**: all nodes publish `brake=1.0, gas=0.0` on shutdown.

---

## Running

```bash
# Terminal 1 — map builder (always needed)
ros2 run auto_nav array_map

# Terminal 2 — choose one controller
ros2 run auto_nav simple_follower
ros2 run auto_nav pure_pursuit
ros2 run auto_nav adaptive_pursuit
ros2 run auto_nav stanley
ros2 run auto_nav mpc
ros2 run auto_nav lqr
ros2 run auto_nav ilqr
```

RViz: add **MarkerArray** on `/map/markers` (Fixed Frame: `Obj_F`) to see boundaries + centreline.
