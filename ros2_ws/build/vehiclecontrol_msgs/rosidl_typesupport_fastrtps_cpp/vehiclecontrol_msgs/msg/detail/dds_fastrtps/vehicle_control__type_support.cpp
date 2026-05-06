// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__functions.h"
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace vehiclecontrol_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
cdr_serialize(
  const vehiclecontrol_msgs::msg::VehicleControl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: use_vc
  cdr << (ros_message.use_vc ? true : false);

  // Member: selector_ctrl
  cdr << ros_message.selector_ctrl;

  // Member: gas
  cdr << ros_message.gas;

  // Member: brake
  cdr << ros_message.brake;

  // Member: steer_ang
  cdr << ros_message.steer_ang;

  // Member: steer_ang_vel
  cdr << ros_message.steer_ang_vel;

  // Member: steer_ang_acc
  cdr << ros_message.steer_ang_acc;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vehiclecontrol_msgs::msg::VehicleControl & ros_message)
{
  // Member: use_vc
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.use_vc = tmp ? true : false;
  }

  // Member: selector_ctrl
  cdr >> ros_message.selector_ctrl;

  // Member: gas
  cdr >> ros_message.gas;

  // Member: brake
  cdr >> ros_message.brake;

  // Member: steer_ang
  cdr >> ros_message.steer_ang;

  // Member: steer_ang_vel
  cdr >> ros_message.steer_ang_vel;

  // Member: steer_ang_acc
  cdr >> ros_message.steer_ang_acc;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
get_serialized_size(
  const vehiclecontrol_msgs::msg::VehicleControl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: use_vc
  {
    size_t item_size = sizeof(ros_message.use_vc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: selector_ctrl
  {
    size_t item_size = sizeof(ros_message.selector_ctrl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gas
  {
    size_t item_size = sizeof(ros_message.gas);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: brake
  {
    size_t item_size = sizeof(ros_message.brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: steer_ang
  {
    size_t item_size = sizeof(ros_message.steer_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: steer_ang_vel
  {
    size_t item_size = sizeof(ros_message.steer_ang_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: steer_ang_acc
  {
    size_t item_size = sizeof(ros_message.steer_ang_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
max_serialized_size_VehicleControl(
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

  // Member: use_vc
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: selector_ctrl
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gas
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: brake
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: steer_ang
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: steer_ang_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: steer_ang_acc
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
    using DataType = vehiclecontrol_msgs::msg::VehicleControl;
    is_plain =
      (
      offsetof(DataType, steer_ang_acc) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
cdr_serialize_key(
  const vehiclecontrol_msgs::msg::VehicleControl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: use_vc
  cdr << (ros_message.use_vc ? true : false);

  // Member: selector_ctrl
  cdr << ros_message.selector_ctrl;

  // Member: gas
  cdr << ros_message.gas;

  // Member: brake
  cdr << ros_message.brake;

  // Member: steer_ang
  cdr << ros_message.steer_ang;

  // Member: steer_ang_vel
  cdr << ros_message.steer_ang_vel;

  // Member: steer_ang_acc
  cdr << ros_message.steer_ang_acc;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
get_serialized_size_key(
  const vehiclecontrol_msgs::msg::VehicleControl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: use_vc
  {
    size_t item_size = sizeof(ros_message.use_vc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: selector_ctrl
  {
    size_t item_size = sizeof(ros_message.selector_ctrl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gas
  {
    size_t item_size = sizeof(ros_message.gas);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: brake
  {
    size_t item_size = sizeof(ros_message.brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: steer_ang
  {
    size_t item_size = sizeof(ros_message.steer_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: steer_ang_vel
  {
    size_t item_size = sizeof(ros_message.steer_ang_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: steer_ang_acc
  {
    size_t item_size = sizeof(ros_message.steer_ang_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehiclecontrol_msgs
max_serialized_size_key_VehicleControl(
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

  // Member: use_vc
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: selector_ctrl
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gas
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: brake
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: steer_ang
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: steer_ang_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: steer_ang_acc
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
    using DataType = vehiclecontrol_msgs::msg::VehicleControl;
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
  auto typed_message =
    static_cast<const vehiclecontrol_msgs::msg::VehicleControl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _VehicleControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vehiclecontrol_msgs::msg::VehicleControl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _VehicleControl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vehiclecontrol_msgs::msg::VehicleControl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _VehicleControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_VehicleControl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _VehicleControl__callbacks = {
  "vehiclecontrol_msgs::msg",
  "VehicleControl",
  _VehicleControl__cdr_serialize,
  _VehicleControl__cdr_deserialize,
  _VehicleControl__get_serialized_size,
  _VehicleControl__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _VehicleControl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_VehicleControl__callbacks,
  get_message_typesupport_handle_function,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_hash,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_description,
  &vehiclecontrol_msgs__msg__VehicleControl__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vehiclecontrol_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vehiclecontrol_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vehiclecontrol_msgs::msg::VehicleControl>()
{
  return &vehiclecontrol_msgs::msg::typesupport_fastrtps_cpp::_VehicleControl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vehiclecontrol_msgs, msg, VehicleControl)() {
  return &vehiclecontrol_msgs::msg::typesupport_fastrtps_cpp::_VehicleControl__handle;
}

#ifdef __cplusplus
}
#endif
