// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from hellocm_msgs:msg/CM2Ext.idl
// generated code does not contain a copyright notice
#ifndef HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "hellocm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hellocm_msgs/msg/detail/cm2_ext__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
bool cdr_serialize_hellocm_msgs__msg__CM2Ext(
  const hellocm_msgs__msg__CM2Ext * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
bool cdr_deserialize_hellocm_msgs__msg__CM2Ext(
  eprosima::fastcdr::Cdr &,
  hellocm_msgs__msg__CM2Ext * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
size_t get_serialized_size_hellocm_msgs__msg__CM2Ext(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
size_t max_serialized_size_hellocm_msgs__msg__CM2Ext(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
bool cdr_serialize_key_hellocm_msgs__msg__CM2Ext(
  const hellocm_msgs__msg__CM2Ext * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
size_t get_serialized_size_key_hellocm_msgs__msg__CM2Ext(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
size_t max_serialized_size_key_hellocm_msgs__msg__CM2Ext(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hellocm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hellocm_msgs, msg, CM2Ext)();

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__CM2_EXT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
