# stanley

## Problem
Pure pursuit tracks a lookahead point but ignores whether the car is actually drifting off the centreline. If the car is running 0.5 m to the right of the path, pure pursuit may not correct it at all if the lookahead point happens to be straight ahead. We need a controller that simultaneously corrects both *lateral position* and *heading*.

## Thought process
Stanley (developed by Stanford's DARPA Grand Challenge team) is the standard step up from pure pursuit. It tracks the **front axle** against the nearest path point and penalises two things at once:

- **Heading error ψ_e**: how much the car's nose deviates from the path tangent — drives the car parallel to the path.
- **Cross-track error e**: how far the front axle is laterally displaced from the path — drives the front axle back onto the path.

The steering law is:
```
δ = ψ_e + arctan(k · e / v)
```

The `arctan` term is important: at high speed `v` is large so the correction is gentle; at low speed `v` is small so the correction is aggressive. Both errors decay to zero together — the car converges onto the path heading AND position simultaneously. Pure pursuit can satisfy one while the other drifts.

**Front axle reference**: Stanley is defined w.r.t. the front axle, not the CoG, so the reference point is offset by `wheelbase` in the heading direction. Assuming odom reports the rear axle position.

**Global speed profile**: instead of the preview-window scan from adaptive_pursuit, stanley computes a full **two-pass velocity profile** once when the map arrives:
- Forward pass: car accelerates at `a_accel`, capped by `sqrt(lat_accel_limit / κ)` at each point.
- Backward pass: working backwards, ensures the car is at the right speed *when it arrives* at each corner, not just when it sees it.

This means the car brakes early on a long straight before a hairpin, and holds full throttle until the mathematically last possible braking point.

**Oscillation fixes applied**:
- Central-difference tangent: yaw at point k uses `pts[k-1] → pts[k+1]` rather than `pts[k] → pts[k+1]`. Spans twice the distance, halving the effect of per-point cone noise.
- Monotonic nearest-point search: only searches 10 points ahead of last known nearest. Prevents the index from jumping backwards between equidistant points on a straight, which would cause `e_psi` to alternate sign and produce steering oscillation.

## Algorithm
1. On path arrival: compute Menger curvatures → two-pass speed profile.
2. Control loop (50 Hz):
   a. Advance nearest index monotonically (window of 10).
   b. Compute front axle position: `(x + L·cos ψ, y + L·sin ψ)`.
   c. CTE: `e = -(tx·dy − ty·dx)` (positive = car right of path → steer left).
   d. Heading error: `ψ_e = path_yaw − car_yaw`, wrapped to (−π, π).
   e. Stanley: `δ = ψ_e + atan2(k·e, max(v, k_soft))`.
   f. Low-pass filter + clamp.
   g. Speed: lookup `v_profile[nearest]`, gas or brake accordingly.

## Topics
| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/map/path` | `nav_msgs/Path` |
| Subscribes | `/carmaker/odom` | `nav_msgs/Odometry` |
| Publishes | `/carmaker/VehicleControl` | `vehiclecontrol_msgs/VehicleControl` |
| Publishes | `/stanley/debug` | `visualization_msgs/MarkerArray` |

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `k` | 1.0 | CTE correction aggressiveness |
| `k_soft` | 0.5 m/s | Minimum effective speed in arctan (prevents over-correction at standstill) |
| `v_max` | 8.0 m/s | Top speed on straights |
| `a_accel` | 4.0 m/s² | Acceleration rate |
| `a_brake` | 8.0 m/s² | Braking rate |
| `lat_accel_limit` | 8.0 m/s² | Corner speed cap |

## Limitations
- Tracks the nearest path point — no predictive look-ahead in the steering law. Cannot anticipate a corner before it arrives (though the speed profile handles this for throttle).
- Assumes odom pose is at the rear axle. If CarMaker reports the CoG, the front-axle offset is wrong.
- No feedforward curvature term in steering — must build up a small heading error to generate cornering steering.
