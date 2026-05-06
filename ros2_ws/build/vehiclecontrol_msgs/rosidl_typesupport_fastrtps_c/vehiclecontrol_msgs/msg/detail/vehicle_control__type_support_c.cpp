// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vehiclecontrol_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__struct.h"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _VehicleControl__ros_msg_type = vehiclecontrol_msgs__msg__VehicleControl;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
bool cdr_serialize_vehiclecontrol_msgs__msg__VehicleControl(
  const vehiclecontrol_msgs__msg__VehicleControl * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: use_vc
  {
    cdr << (ros_message->use_vc ? true : false);
  }

  // Field name: selector_ctrl
  {
    cdr << ros_message->selector_ctrl;
  }

  // Field name: gas
  {
    cdr << ros_message->gas;
  }

  // Field name: brake
  {
    cdr << ros_message->brake;
  }

  // Field name: steer_ang
  {
    cdr << ros_message->steer_ang;
  }

  // Field name: steer_ang_vel
  {
    cdr << ros_message->steer_ang_vel;
  }

  // Field name: steer_ang_acc
  {
    cdr << ros_message->steer_ang_acc;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
bool cdr_deserialize_vehiclecontrol_msgs__msg__VehicleControl(
  eprosima::fastcdr::Cdr & cdr,
  vehiclecontrol_msgs__msg__VehicleControl * ros_message)
{
  // Field name: use_vc
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->use_vc = tmp ? true : false;
  }

  // Field name: selector_ctrl
  {
    cdr >> ros_message->selector_ctrl;
  }

  // Field name: gas
  {
    cdr >> ros_message->gas;
  }

  // Field name: brake
  {
    cdr >> ros_message->brake;
  }

  // Field name: steer_ang
  {
    cdr >> ros_message->steer_ang;
  }

  // Field name: steer_ang_vel
  {
    cdr >> ros_message->steer_ang_vel;
  }

  // Field name: steer_ang_acc
  {
    cdr >> ros_message->steer_ang_acc;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t get_serialized_size_vehiclecontrol_msgs__msg__VehicleControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleControl__ros_msg_type * ros_message = static_cast<const _VehicleControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: use_vc
  {
    size_t item_size = sizeof(ros_message->use_vc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: selector_ctrl
  {
    size_t item_size = sizeof(ros_message->selector_ctrl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gas
  {
    size_t item_size = sizeof(ros_message->gas);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: brake
  {
    size_t item_size = sizeof(ros_message->brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steer_ang
  {
    size_t item_size = sizeof(ros_message->steer_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steer_ang_vel
  {
    size_t item_size = sizeof(ros_message->steer_ang_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steer_ang_acc
  {
    size_t item_size = sizeof(ros_message->steer_ang_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t max_serialized_size_vehiclecontrol_msgs__msg__VehicleControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: use_vc
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: selector_ctrl
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gas
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: brake
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steer_ang
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steer_ang_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steer_ang_acc
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vehiclecontrol_msgs__msg__VehicleControl;
    is_plain =
      (
      offsetof(DataType, steer_ang_acc) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
bool cdr_serialize_key_vehiclecontrol_msgs__msg__VehicleControl(
  const vehiclecontrol_msgs__msg__VehicleControl * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: use_vc
  {
    cdr << (ros_message->use_vc ? true : false);
  }

  // Field name: selector_ctrl
  {
    cdr << ros_message->selector_ctrl;
  }

  // Field name: gas
  {
    cdr << ros_message->gas;
  }

  // Field name: brake
  {
    cdr << ros_message->brake;
  }

  // Field name: steer_ang
  {
    cdr << ros_message->steer_ang;
  }

  // Field name: steer_ang_vel
  {
    cdr << ros_message->steer_ang_vel;
  }

  // Field name: steer_ang_acc
  {
    cdr << ros_message->steer_ang_acc;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t get_serialized_size_key_vehiclecontrol_msgs__msg__VehicleControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleControl__ros_msg_type * ros_message = static_cast<const _VehicleControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: use_vc
  {
    size_t item_size = sizeof(ros_message->use_vc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: selector_ctrl
  {
    size_t item_size = sizeof(ros_message->selector_ctrl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gas
  {
    size_t item_size = sizeof(ros_message->gas);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: brake
  {
    size_t item_size = sizeof(ros_message->brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steer_ang
  {
    size_t item_size = sizeof(ros_message->steer_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steer_ang_vel
  {
    size_t item_size = sizeof(ros_message->steer_ang_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steer_ang_acc
  {
    size_t item_size = sizeof(ros_message->steer_ang_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vehiclecontrol_msgs
size_t max_serialized_size_key_vehiclecontrol_msgs__msg__VehicleControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: use_vc
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: selector_ctrl
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: gas
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: brake
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steer_ang
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steer_ang_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steer_ang_acc
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vehiclecontrol_msgs__msg__VehicleControl;
    is_plain =
      (
      offsetof(DataType, steer_ang_acc) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _VehicleControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const vehiclecontrol_msgs__msg__VehicleControl * ros_message = static_cast<const vehiclecontrol_msgs__msg__VehicleControl *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_vehiclecontrol_msgs__msg__VehicleControl(ros_message, cdr);
}

static bool _VehicleControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  vehiclecontrol_msgs__msg__VehicleControl * ros_message = static_cast<vehiclecontrol_msgs__msg__VehicleControl *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_vehiclecontrol_msgs__msg__VehicleControl(cdr, ros_message);
}

static uint32_t _VehicleControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vehiclecontrol_msgs__msg__VehicleControl(
      untyped_ros_message, 0));
}

static size_t _VehicleControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vehiclecontrol_msgs__msg__VehicleControl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VehicleControl = {
  "vehiclecontrol_msgs::msg",
  "VehicleControl",
  _VehicleControl__cdr_serialize,
  _VehicleControl__cdr_deserialize,
  _VehicleControl__get_serialized_size,
  _VehicleControl__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _VehicleControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehicleControl,
  get_message_typesupport_handle_function,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_hash,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_description,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vehiclecontrol_msgs, msg, VehicleControl)() {
  return &_VehicleControl__type_support;
}

#if defined(__cplusplus)
}
#endif
