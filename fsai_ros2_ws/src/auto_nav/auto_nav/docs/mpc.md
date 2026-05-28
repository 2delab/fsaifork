# mpc

## Problem
Stanley reacts to the current nearest point but has no look-ahead in its steering law. It cannot trade off present error against future error — it will always steer maximally to correct now even if a gentler correction over the next 10 steps would be smoother and faster overall.

## Thought process
Model Predictive Control solves this by rolling out the vehicle dynamics N steps ahead and finding the control sequence that minimises total future cost. Only the first control is applied (receding horizon), then the problem is re-solved at the next tick with a shifted warm start.

**Self-contained design**: the node derives all path data (heading, curvature, speed profile) internally from the raw `/map/path` positions. No changes to `array_map` are needed.

**Solver choice**: CasADi/IPOPT (used by winning FS teams) was not installed and pip was unavailable. `scipy.optimize.minimize` with L-BFGS-B is available and sufficient for a 20-variable problem (N=10 steps × 2 control variables... actually just N=10 steering values since speed is handled separately).

**Error-state formulation**: rather than optimising over absolute states `[X, Y, ψ, v]`, the MPC works in error space `[e_cte, e_psi]`. This reduces the problem from 4 states to 2, halving the solve time, and makes the cost function directly interpretable (penalise CTE and heading error).

**Nonlinear rollout**: the cost function uses the actual nonlinear bicycle error dynamics (not linearised), so the optimiser sees the true effect of each steering input including the `tan(δ)` nonlinearity. scipy's L-BFGS-B computes gradients numerically.

**Warm start**: the previous solution is shifted by one step (`u[1..N], 0`) to initialise the next solve. This dramatically reduces iterations needed (typically 3–7 instead of 15–20).

**Speed**: same global two-pass profile as stanley, computed once on path arrival.

## Algorithm
1. On path arrival: compute curvatures → two-pass speed profile (stored as `path_v_ref`).
2. Control loop (50 Hz):
   a. Find nearest path index.
   b. Compute `e_cte`, `e_psi` at current car position.
   c. Collect reference curvatures for the N-step horizon.
   d. Minimise cost over N steering values using scipy L-BFGS-B (warm-started).
   e. Apply first steering value; shift solution for next tick.
   f. Speed from profile.

Cost per step: `w_cte·e_cte² + w_psi·e_psi² + w_steer·δ² + w_dsteer·Δδ²`

## Topics
| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/map/path` | `nav_msgs/Path` |
| Subscribes | `/carmaker/odom` | `nav_msgs/Odometry` |
| Publishes | `/carmaker/VehicleControl` | `vehiclecontrol_msgs/VehicleControl` |
| Publishes | `/mpc/debug` | `visualization_msgs/MarkerArray` |

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `N` | 10 | Horizon steps — higher = smoother, slower to solve |
| `dt` | 0.1 s | Model timestep |
| `w_cte` | 2.0 | Penalise lateral drift |
| `w_psi` | 1.0 | Penalise heading error |
| `w_steer` | 0.1 | Penalise steering magnitude |
| `w_dsteer` | 0.5 | Penalise steering rate — raise to smooth |

## Limitations
- scipy L-BFGS-B with `maxiter=20` may not fully converge at high curvature — the warm start usually compensates.
- No CasADi: if solve time exceeds 20 ms, the control loop misses a tick. With N=10 and warm starting, typical solve time is 3–8 ms on this hardware.
- If CasADi becomes available, the cost function can be replaced with a CasADi symbolic expression for exact gradients and much faster solves.
