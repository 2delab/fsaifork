// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice
#ifndef VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "vehiclecontrol_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
bool cdr_serialize_vehiclecontrol_msgs__msg__VehicleControl(
  const vehiclecontrol_msgs__msg__VehicleControl * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
bool cdr_deserialize_vehiclecontrol_msgs__msg__VehicleControl(
  eprosima::fastcdr::Cdr &,
  vehiclecontrol_msgs__msg__VehicleControl * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t get_serialized_size_vehiclecontrol_msgs__msg__VehicleControl(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t max_serialized_size_vehiclecontrol_msgs__msg__VehicleControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
bool cdr_serialize_key_vehiclecontrol_msgs__msg__VehicleControl(
  const vehiclecontrol_msgs__msg__VehicleControl * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t get_serialized_size_key_vehiclecontrol_msgs__msg__VehicleControl(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t max_serialized_size_key_vehiclecontrol_msgs__msg__VehicleControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vehiclecontrol_msgs, msg, VehicleControl)();

#ifdef __cplusplus
}
#endif

#endif  // VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
