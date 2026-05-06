// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection.h"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__STRUCT_H_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CameraDetection in the package camera_msgs.
/**
  * ~~~~~~~~~~ Custom ROS message for HiFi Camera Sensor ~~~~~~~~~~
 */
typedef struct camera_msgs__msg__CameraDetection
{
  /// ~~~~~ Quantities match UAQs for HiFi Camera Sensor in CM
  /// ~~~~~ See 'Reference Manual --> User Accessible Quantities --> Sensors --> Camera Sensor' for full descriptions.
  ///  global ID to identify object (integer)
  int32_t objid;
  /// camera object type (integer)
  ///   0 - Car
  ///   1 - Truck
  ///   2 - Bicycle
  ///   3 - Pedestrian
  ///   4 - Traffic sign
  ///   5 - Traffic light
  int8_t objecttype;
  /// number of visible pixels (integer)
  int64_t nvispixels;
  /// indicates how much of the object is visible
  double confidence;
  /// minimum bounding rectangle - bottom left and top right points
  double mbr_bl_x;
  double mbr_bl_y;
  double mbr_bl_z;
  double mbr_tr_x;
  double mbr_tr_y;
  double mbr_tr_z;
  /// 0: not facing sensor, 1: facing sensor
  int8_t facing;
  /// Traffic light state/phase (integer):
  ///   0: All lights off
  ///   1: Green light on
  ///   2: Yellow light on
  ///   3: Red light on
  ///   4: Red-Yellow light on
  int8_t lightstate;
  /// User defined sign attribute values
  double signmain_val0;
  double signmain_val1;
  double signsuppl1_val0;
  double signsuppl1_val1;
  double signsuppl2_val0;
  double signsuppl2_val1;
} camera_msgs__msg__CameraDetection;

// Struct for a sequence of camera_msgs__msg__CameraDetection.
typedef struct camera_msgs__msg__CameraDetection__Sequence
{
  camera_msgs__msg__CameraDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_msgs__msg__CameraDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__STRUCT_H_
