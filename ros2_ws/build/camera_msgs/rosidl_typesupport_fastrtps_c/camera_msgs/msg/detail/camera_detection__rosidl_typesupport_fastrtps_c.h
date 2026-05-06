// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice
#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "camera_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "camera_msgs/msg/detail/camera_detection__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
bool cdr_serialize_camera_msgs__msg__CameraDetection(
  const camera_msgs__msg__CameraDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
bool cdr_deserialize_camera_msgs__msg__CameraDetection(
  eprosima::fastcdr::Cdr &,
  camera_msgs__msg__CameraDetection * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t get_serialized_size_camera_msgs__msg__CameraDetection(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t max_serialized_size_camera_msgs__msg__CameraDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
bool cdr_serialize_key_camera_msgs__msg__CameraDetection(
  const camera_msgs__msg__CameraDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t get_serialized_size_key_camera_msgs__msg__CameraDetection(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t max_serialized_size_key_camera_msgs__msg__CameraDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, camera_msgs, msg, CameraDetection)();

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
