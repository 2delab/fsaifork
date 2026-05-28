# pure_pursuit

## Problem
The simple_follower reacts only to the nearest cones and has no look-ahead. At any real speed it steers too late. We need a controller that targets a point further ahead and uses a proper geometric steering formula.

## Thought process
Pure pursuit is the standard entry-level racing controller. The idea is to pick a point on the path a fixed distance (the lookahead) ahead of the car and steer toward it using the Ackermann curvature formula. It is well-understood, has one main tuning knob (lookahead distance), and performs well on gentle tracks at moderate speeds.

The first version subscribed to `/carmaker/ObjectList` and classified cones by colour to find the target. This worked but had two problems:
1. It depended on colour labels, which are not reliable (87 of 128 cones in our track are white/unclassified).
2. It could only use visible cones — no pre-built map.

After `array_map` was built, pure_pursuit was updated to subscribe to `/map/path` (the pre-built centreline) and `/carmaker/odom` (car pose), completely removing the colour dependency. The lookahead point is found by walking forward along the closed-loop path from the nearest point until reaching `lookahead_distance` metres.

## Algorithm
1. Subscribe to `/map/path` and `/carmaker/odom`.
2. Find the path point nearest to the car.
3. Walk forward along the path (wrapping at the end) until a point ≥ `lookahead_distance` away is found.
4. Transform that point into vehicle frame using car yaw from odom.
5. Apply pure pursuit: `κ = 2y / L²`, `δ = atan(κ · wheelbase)`.
6. Publish at 50 Hz.

## Topics
| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/map/path` | `nav_msgs/Path` |
| Subscribes | `/carmaker/odom` | `nav_msgs/Odometry` |
| Publishes | `/carmaker/VehicleControl` | `vehiclecontrol_msgs/VehicleControl` |
| Publishes | `/pure_pursuit/target` | `visualization_msgs/Marker` |

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `lookahead_distance` | 6.0 m | Larger = smoother but cuts corners |
| `constant_gas` | 0.3 | Fixed throttle — no speed planning |
| `max_steering` | 0.6 rad | Steering clamp |
| `wheelbase` | 1.53 m | Ackermann geometry |
| `steering_alpha` | 0.3 | Low-pass filter on steering output |

## Limitations
- Fixed lookahead means the car is always as reactive (or as sluggish) at every speed. At high speed it cuts corners; at low speed it oscillates.
- Constant gas — no speed planning at all.
- Tracks only position, not heading — can enter a corner well but exit it poorly.
