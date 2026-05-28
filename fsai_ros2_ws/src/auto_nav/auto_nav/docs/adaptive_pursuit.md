# adaptive_pursuit

## Problem
Pure pursuit uses a fixed lookahead and constant throttle. At high speed the fixed lookahead is too short — the car sees corners too late. At low speed it is too long — the car oscillates. Throttle is never adjusted for corners.

## Thought process
Two independent improvements over pure pursuit:

**Adaptive lookahead**: lookahead should scale with speed so the car always "sees" the same time horizon ahead (`lookahead = speed × lookahead_time`). At 10 m/s with 1.5 s time, that is 15 m ahead. At 2 m/s it is 3 m — just enough to make the next gate.

**Preview-based speed control**: the reactive approach (reduce gas when currently turning) is too late — the car is already mid-corner by the time it slows down. Instead, scan the path curvature over a `preview_distance` window ahead and target the physically safe speed for the worst upcoming corner:

```
v_safe = sqrt(lat_accel_limit / κ_max)
```

This comes from centripetal acceleration `a = v²·κ`. If `κ_max` is large (tight corner incoming), `v_safe` is small — the car brakes *before* reaching the corner, not during it.

If `car_speed > v_safe`: apply proportional braking.
If `car_speed < v_safe`: ramp gas up to `max_gas`.

The preview window approach is still reactive to some extent — it knows about corners only within `preview_distance` metres. This was later replaced entirely by the global two-pass speed profile in stanley/lqr/ilqr.

## Algorithm
1. Same path/odom subscriptions as pure_pursuit.
2. Lookahead = clamp(speed × lookahead_time, min_lookahead, max_lookahead).
3. Find lookahead point by walking forward from nearest path point.
4. Pure pursuit steering in vehicle frame.
5. Scan curvature over preview_distance ahead; compute v_safe; gas or brake accordingly.

## Topics
Same as pure_pursuit, publishes to `/adaptive_pursuit/target`.

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `lookahead_time` | 1.5 s | Time horizon for lookahead |
| `min_lookahead` | 3.0 m | Floor |
| `max_lookahead` | 20.0 m | Ceiling |
| `lat_accel_limit` | 8.0 m/s² | Higher = faster cornering |
| `preview_distance` | 15.0 m | How far ahead to scan for corners |
| `max_gas` | 0.4 | Top throttle on straights |

## Limitations
- Still pure pursuit for steering — no cross-track error correction.
- Preview window is a local scan, not a global plan. A tight corner 30 m ahead is invisible until the car is 15 m from it.
- Speed planning was superseded by the global two-pass profile in later nodes.
