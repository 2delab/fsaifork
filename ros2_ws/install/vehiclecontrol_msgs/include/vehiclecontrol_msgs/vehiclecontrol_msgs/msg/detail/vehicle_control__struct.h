// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "vehiclecontrol_msgs/msg/vehicle_control.h"


#ifndef VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_H_
#define VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/VehicleControl in the package vehiclecontrol_msgs.
/**
  * ---------- ROS Message to map external signals to CarMaker Vehicle Control Quantities ---------- 
  * *** Most of VC Interface outlined here...uncomment relevant quantities and assign in CMNode as demonstrated. ***
 */
typedef struct vehiclecontrol_msgs__msg__VehicleControl
{
  /// ----- Flag to Use VC Input -----
  ///  Set this flag to 1 in order to start writing to CarMaker VC quantities in this message.
  ///    --> Used so that zeros are not sent over topic when no node is publishing to steer, brake, gas, etc.
  ///    --> Allows driver or DiL to drive the vehicle via DM quantities and not be overwritten by VC if not needed.
  ///    0: Key out
  ///    1: Key in, power off
  ///    2: Key in, power accessory
  ///    3: Key in, power on
  ///    4: Key in, starter active
  ///    0=off
  ///    1=on
  bool use_vc;
  /// ----- Key / StartStop Button -----
  /// int8 key                # Vehicle key position (integer):
  /// bool sst                # Powertrain start-stop button (boolean):
  /// ----- Transmission -----
  ///  PRNDL Position
  ///    -9 = Park
  ///    -1 = Reverse
  ///     0 = Neutral
  ///     1 = Drive
  ///     2 = Manual gear selection (requires Manumatic transmission in CM model)
  int8_t selector_ctrl;
  /// int8 gear               # Gear number for manual transmission...uncomment for use with manual transmission model.
  /// ----- Pedals -----
  ///  Gas pedal position
  double gas;
  /// Brake pedal position
  double brake;
  /// float64 clutch         # Clutch pedal position [0 - 1]...uncomment for use with manual transmission model.
  /// ----- Steering -----
  ///  Steer angle [rad]
  double steer_ang;
  /// Steer angle velocity
  double steer_ang_vel;
  /// Steer angle acceleration
  double steer_ang_acc;
} vehiclecontrol_msgs__msg__VehicleControl;

// Struct for a sequence of vehiclecontrol_msgs__msg__VehicleControl.
typedef struct vehiclecontrol_msgs__msg__VehicleControl__Sequence
{
  vehiclecontrol_msgs__msg__VehicleControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehiclecontrol_msgs__msg__VehicleControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_H_
