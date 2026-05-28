# simple_follower

## Problem
The simplest possible controller to get the car moving around the track. Used as a baseline and sanity check before implementing anything more sophisticated.

## Thought process
Before writing any real controller we needed something that would just drive the car forward and steer toward the gap between cones. The idea: find the closest blue cone and the closest yellow cone, take their midpoint, and steer toward it at a constant speed. No path, no model, no optimisation.

This is deliberately naïve. It only uses the two nearest cones, so it has no look-ahead and will react too late at any speed above walking pace. Its value is that it is trivially debuggable — if it fails, the problem is in the simulator or the topic pipeline, not in the controller.

## Algorithm
1. Subscribe to `/carmaker/ObjectList`, classify cones by colour (blue = left, yellow = right).
2. Find the closest blue and closest yellow cone by Euclidean distance.
3. Target point = midpoint of those two cones.
4. Steering = `atan2(target_y, target_x) × gain` — a proportional angle toward the target.
5. Publish constant gas + computed steering at 50 Hz.

## Topics
| Direction | Topic | Type |
|-----------|-------|------|
| Subscribes | `/carmaker/ObjectList` | `visualization_msgs/MarkerArray` |
| Publishes | `/carmaker/VehicleControl` | `vehiclecontrol_msgs/VehicleControl` |

## Parameters
| Parameter | Default | Effect |
|-----------|---------|--------|
| `constant_gas` | 0.3 | Fixed throttle |
| `max_steering` | 0.6 rad | Steering clamp |
| `steering_gain` | 1.0 | Proportional gain on angle to target |

## Limitations
- Reacts only to the two nearest cones — no look-ahead, extremely slow safe speed.
- Colour-dependent: fails completely if cones are not blue/yellow (e.g. white in CarMaker).
- Not suitable for any real mission — exists only as a baseline.
