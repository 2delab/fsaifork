// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection_array.h"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__STRUCT_H_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'detections'
#include "camera_msgs/msg/detail/camera_detection__struct.h"

/// Struct defined in msg/CameraDetectionArray in the package camera_msgs.
/**
  * ~~~~~~~~~~ Custom ROS message for Camera HiFi Sensor Object List (array of detections) ~~~~~~~~~~
 */
typedef struct camera_msgs__msg__CameraDetectionArray
{
  camera_msgs__msg__CameraDetection__Sequence detections;
} camera_msgs__msg__CameraDetectionArray;

// Struct for a sequence of camera_msgs__msg__CameraDetectionArray.
typedef struct camera_msgs__msg__CameraDetectionArray__Sequence
{
  camera_msgs__msg__CameraDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_msgs__msg__CameraDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__STRUCT_H_
