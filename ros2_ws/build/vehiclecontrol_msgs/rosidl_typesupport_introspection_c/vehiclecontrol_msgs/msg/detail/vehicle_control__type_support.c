// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__rosidl_typesupport_introspection_c.h"
#include "vehiclecontrol_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__functions.h"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vehiclecontrol_msgs__msg__VehicleControl__init(message_memory);
}

void vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_fini_function(void * message_memory)
{
  vehiclecontrol_msgs__msg__VehicleControl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_member_array[7] = {
  {
    "use_vc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, use_vc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "selector_ctrl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, selector_ctrl),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gas",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, gas),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "brake",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, brake),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steer_ang",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, steer_ang),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steer_ang_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, steer_ang_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steer_ang_acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehiclecontrol_msgs__msg__VehicleControl, steer_ang_acc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_members = {
  "vehiclecontrol_msgs__msg",  // message namespace
  "VehicleControl",  // message name
  7,  // number of fields
  sizeof(vehiclecontrol_msgs__msg__VehicleControl),
  false,  // has_any_key_member_
  vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_member_array,  // message members
  vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_init_function,  // function to initialize message memory (memory has to be allocated)
  vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_type_support_handle = {
  0,
  &vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_members,
  get_message_typesupport_handle_function,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_hash,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_description,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vehiclecontrol_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehiclecontrol_msgs, msg, VehicleControl)() {
  if (!vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_type_support_handle.typesupport_identifier) {
    vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vehiclecontrol_msgs__msg__VehicleControl__rosidl_typesupport_introspection_c__VehicleControl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
