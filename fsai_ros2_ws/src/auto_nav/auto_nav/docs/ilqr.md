# ilqr

## Problem
LQR linearises the bicycle model at `e=0` (the reference path) and uses that single linearisation everywhere. When the car deviates significantly — e.g. on a tight corner entry at speed — the model mismatch grows and the gain is no longer optimal. The main nonlinearity that matters is `d/dδ [tan(δ)] = sec²(δ)`: at large steering angles the effective gain of the steering actuator drops, so LQR underestimates how much steering is needed to correct the heading.

## Thought process
iLQR (Iterative LQR) solves this by re-linearising around the *actual predicted trajectory* rather than the reference path, iterating until the predicted trajectory and the linearisation are consistent.

**Why not just use MPC?** The scipy MPC uses numerical finite-difference gradients, which are both slow and inaccurate. iLQR computes the exact analytical gradient of the nonlinear dynamics at each step, giving faster convergence (fewer iterations) and better numerical stability.

**Error-state formulation**: same 2D error state `[e_cte, e_psi]` as LQR and MPC. The nonlinear dynamics are:
```
e_cte[k+1] = e_cte[k] + v·sin(e_psi[k])·dt
e_psi[k+1] = e_psi[k] + v/L·tan(δ[k])·dt − κ_k·v·dt
```
Linearising at the current rollout point `(ē, δ̄)`:
```
A = [[1,  v·cos(e_psi)·dt ],    B = [[        0          ]
     [0,       1          ]]        [ v·dt/(L·cos²(δ)) ]]
```
Note `B[1,0] = v·dt/(L·cos²(δ))` — this is larger when `δ` is small and smaller when `δ` is large, capturing the nonlinearity LQR misses.

**Per-iteration structure**:
1. **Forward rollout**: simulate nonlinear dynamics with current controls → trajectory `Ē`.
2. **Backward pass**: linearise at each `Ē_k`, run Riccati recursion backwards to get per-step feedforward `k_k` (scalar) and feedback `K_k` (1×2 row).
3. **Forward update**: `δ_k = δ̄_k + k_k + K_k·(ẽ_k − ē_k)`, roll out again.

With warm-starting (previous solution shifted by 1 step), 3 iterations is typically sufficient for convergence on a well-tracked path.

**Warm start**: previous control sequence shifted by one step. Without this, cold-start convergence would require ~10 iterations and exceed the 20 ms budget.

**Speed**: same global two-pass profile as stanley/lqr.

**Oscillation fixes**: central-difference tangents + monotonic nearest-point search, same as lqr.

## Riccati recursion detail
Terminal: `V_x = Q·ē_N`, `V_xx = Q`

For k = N−1 to 0:
```
Q_uu = R + Bᵀ V_xx B       (scalar)
Q_ux = Bᵀ V_xx A            (1×2)
Q_u  = R·δ̄_k + Bᵀ V_x      (scalar)
Q_x  = Q·ē_k + Aᵀ V_x      (2-vector)
Q_xx = Q + Aᵀ V_xx A        (2×2)

k_k  = −Q_uu⁻¹ · Q_u       feedforward (scalar)
K_k  = −Q_uu⁻¹ · Q_ux      feedback    (1×2)

V_x  ← Q_x  − Q_ux^T · Q_uu⁻¹ · Q_u
V_xx ← Q_xx − Q_uu⁻¹ · Q_ux^T · Q_ux
```

## Topics
| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/map/path` | `nav_msgs/Path` |
| Subscribes | `/carmaker/odom` | `nav_msgs/Odometry` |
| Publishes | `/carmaker/VehicleControl` | `vehiclecontrol_msgs/VehicleControl` |
| Publishes | `/ilqr/debug` | `visualization_msgs/MarkerArray` |

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `N` | 10 | Horizon steps at `dt` each |
| `dt` | 0.1 s | Planning timestep (longer than control rate — gives 1 s horizon) |
| `n_iter` | 3 | iLQR iterations per tick — increase if car overshoots corners |
| `q_cte` | 2.0 | CTE cost — raise to stay closer to centreline |
| `q_psi` | 1.0 | Heading cost |
| `r_steer` | 0.1 | Steering effort — raise to smooth |

## Compared to LQR
| | LQR | iLQR |
|---|---|---|
| Linearisation point | `e=0` always | Current predicted trajectory |
| Handles large deviations | Suboptimal | Accurate |
| Runtime per tick | ~1 µs | ~0.5–1 ms (3 iters, N=10) |
| Feedforward | Yes (κ·L) | Implicit in backward pass |

## Limitations
- `n_iter=3` with warm start is accurate for small-to-medium deviations. After a large disturbance (e.g. collision) the warm start is invalid — the first tick may produce a suboptimal control before convergence catches up.
- Same `cos²(δ)` regularisation (`+1e-9`) as everywhere — if `δ` saturates at `max_steering` frequently, the `B` matrix becomes inaccurate and more iterations are needed.
