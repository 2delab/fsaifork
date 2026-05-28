# lqr

## Problem
MPC requires online numerical optimisation every tick. With scipy this costs 3–8 ms per solve. We want near-MPC accuracy with essentially zero runtime cost.

## Thought process
LQR solves the MPC problem analytically — but only once, offline, before driving starts. The key insight: if the vehicle dynamics are linear (or can be linearised), the optimal gain matrix K that minimises `Σ xᵀQx + uᵀRu` over an infinite horizon can be computed by solving the Discrete Algebraic Riccati Equation (DARE). The control is then just:

```
δ = -K · [e_cte, e_psi]ᵀ
```

A single matrix multiply at runtime — microseconds rather than milliseconds.

**LTV (Linear Time-Varying)**: the linearised bicycle model depends on speed (`A` and `B` matrices both contain `v`). Rather than computing K at a single nominal speed, we solve the DARE for each path point using its reference speed from the two-pass profile. Results are cached by speed (rounded to 0.01 m/s) so we only solve DARE once per unique speed value — typically 10–20 unique speeds for a full track.

**Feedforward**: LQR feedback alone would need to build up a heading error `e_psi` in order to generate the steering needed for a curved section. Adding a feedforward term `δ_ff = arctan(κ·L)` gives the car the correct steering for the current curvature immediately, with the feedback term correcting any residual error only. This eliminates the systematic lateral offset that pure feedback causes on corners.

**Oscillation fixes** (same as stanley):
- Central-difference tangent at each path point.
- Monotonic nearest-point search (window of 10) to prevent index jumping on straights.

**Speed**: same global two-pass profile as stanley.

## Algorithm
1. On path arrival:
   a. Compute central-difference tangents and Menger curvatures.
   b. Compute two-pass speed profile.
   c. For each path point, solve DARE with local speed → K[k] (cached by speed).
2. Control loop (50 Hz):
   a. Monotonic nearest index search.
   b. Compute `e_cte` and `e_psi`.
   c. Feedforward: `δ_ff = arctan(κ · L)`.
   d. Feedback: `δ_fb = -(K[nearest] · [e_cte, e_psi]ᵀ)[0]`.
   e. `δ = δ_ff + δ_fb`, low-pass filter, clamp.
   f. Speed from profile.

## Topics
| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/map/path` | `nav_msgs/Path` |
| Subscribes | `/carmaker/odom` | `nav_msgs/Odometry` |
| Publishes | `/carmaker/VehicleControl` | `vehiclecontrol_msgs/VehicleControl` |
| Publishes | `/lqr/debug` | `visualization_msgs/MarkerArray` |

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `q_cte` | 1.0 | CTE cost weight — raise to penalise drift |
| `q_psi` | 1.0 | Heading cost weight |
| `r_steer` | 0.1 | Steering effort cost — raise to smooth |
| `dt` | 0.02 s | Model timestep (matches control rate) |

## Limitations
- Linearised at `e=0`: the gain K is optimal when the car is near the path. For large deviations (e.g. after a spin) the linear model is inaccurate and the gain is suboptimal. iLQR fixes this.
- Infinite-horizon DARE ignores the constraint that the path is finite-length — in practice this is fine for a closed loop.
- Assumes rear-axle odom pose (same as stanley).
