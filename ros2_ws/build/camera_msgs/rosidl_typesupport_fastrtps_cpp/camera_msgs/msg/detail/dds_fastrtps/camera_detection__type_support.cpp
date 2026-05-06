// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice
#include "camera_msgs/msg/detail/camera_detection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "camera_msgs/msg/detail/camera_detection__functions.h"
#include "camera_msgs/msg/detail/camera_detection__struct.hpp"

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

namespace camera_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
cdr_serialize(
  const camera_msgs::msg::CameraDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: objid
  cdr << ros_message.objid;

  // Member: objecttype
  cdr << ros_message.objecttype;

  // Member: nvispixels
  cdr << ros_message.nvispixels;

  // Member: confidence
  cdr << ros_message.confidence;

  // Member: mbr_bl_x
  cdr << ros_message.mbr_bl_x;

  // Member: mbr_bl_y
  cdr << ros_message.mbr_bl_y;

  // Member: mbr_bl_z
  cdr << ros_message.mbr_bl_z;

  // Member: mbr_tr_x
  cdr << ros_message.mbr_tr_x;

  // Member: mbr_tr_y
  cdr << ros_message.mbr_tr_y;

  // Member: mbr_tr_z
  cdr << ros_message.mbr_tr_z;

  // Member: facing
  cdr << ros_message.facing;

  // Member: lightstate
  cdr << ros_message.lightstate;

  // Member: signmain_val0
  cdr << ros_message.signmain_val0;

  // Member: signmain_val1
  cdr << ros_message.signmain_val1;

  // Member: signsuppl1_val0
  cdr << ros_message.signsuppl1_val0;

  // Member: signsuppl1_val1
  cdr << ros_message.signsuppl1_val1;

  // Member: signsuppl2_val0
  cdr << ros_message.signsuppl2_val0;

  // Member: signsuppl2_val1
  cdr << ros_message.signsuppl2_val1;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  camera_msgs::msg::CameraDetection & ros_message)
{
  // Member: objid
  cdr >> ros_message.objid;

  // Member: objecttype
  cdr >> ros_message.objecttype;

  // Member: nvispixels
  cdr >> ros_message.nvispixels;

  // Member: confidence
  cdr >> ros_message.confidence;

  // Member: mbr_bl_x
  cdr >> ros_message.mbr_bl_x;

  // Member: mbr_bl_y
  cdr >> ros_message.mbr_bl_y;

  // Member: mbr_bl_z
  cdr >> ros_message.mbr_bl_z;

  // Member: mbr_tr_x
  cdr >> ros_message.mbr_tr_x;

  // Member: mbr_tr_y
  cdr >> ros_message.mbr_tr_y;

  // Member: mbr_tr_z
  cdr >> ros_message.mbr_tr_z;

  // Member: facing
  cdr >> ros_message.facing;

  // Member: lightstate
  cdr >> ros_message.lightstate;

  // Member: signmain_val0
  cdr >> ros_message.signmain_val0;

  // Member: signmain_val1
  cdr >> ros_message.signmain_val1;

  // Member: signsuppl1_val0
  cdr >> ros_message.signsuppl1_val0;

  // Member: signsuppl1_val1
  cdr >> ros_message.signsuppl1_val1;

  // Member: signsuppl2_val0
  cdr >> ros_message.signsuppl2_val0;

  // Member: signsuppl2_val1
  cdr >> ros_message.signsuppl2_val1;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
get_serialized_size(
  const camera_msgs::msg::CameraDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: objid
  {
    size_t item_size = sizeof(ros_message.objid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: objecttype
  {
    size_t item_size = sizeof(ros_message.objecttype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: nvispixels
  {
    size_t item_size = sizeof(ros_message.nvispixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: confidence
  {
    size_t item_size = sizeof(ros_message.confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_bl_x
  {
    size_t item_size = sizeof(ros_message.mbr_bl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_bl_y
  {
    size_t item_size = sizeof(ros_message.mbr_bl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_bl_z
  {
    size_t item_size = sizeof(ros_message.mbr_bl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_tr_x
  {
    size_t item_size = sizeof(ros_message.mbr_tr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_tr_y
  {
    size_t item_size = sizeof(ros_message.mbr_tr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_tr_z
  {
    size_t item_size = sizeof(ros_message.mbr_tr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: facing
  {
    size_t item_size = sizeof(ros_message.facing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: lightstate
  {
    size_t item_size = sizeof(ros_message.lightstate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signmain_val0
  {
    size_t item_size = sizeof(ros_message.signmain_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signmain_val1
  {
    size_t item_size = sizeof(ros_message.signmain_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl1_val0
  {
    size_t item_size = sizeof(ros_message.signsuppl1_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl1_val1
  {
    size_t item_size = sizeof(ros_message.signsuppl1_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl2_val0
  {
    size_t item_size = sizeof(ros_message.signsuppl2_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl2_val1
  {
    size_t item_size = sizeof(ros_message.signsuppl2_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
max_serialized_size_CameraDetection(
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

  // Member: objid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: objecttype
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: nvispixels
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mbr_bl_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mbr_bl_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mbr_bl_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mbr_tr_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mbr_tr_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: mbr_tr_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: facing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: lightstate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: signmain_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: signmain_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: signsuppl1_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: signsuppl1_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: signsuppl2_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: signsuppl2_val1
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
    using DataType = camera_msgs::msg::CameraDetection;
    is_plain =
      (
      offsetof(DataType, signsuppl2_val1) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
cdr_serialize_key(
  const camera_msgs::msg::CameraDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: objid
  cdr << ros_message.objid;

  // Member: objecttype
  cdr << ros_message.objecttype;

  // Member: nvispixels
  cdr << ros_message.nvispixels;

  // Member: confidence
  cdr << ros_message.confidence;

  // Member: mbr_bl_x
  cdr << ros_message.mbr_bl_x;

  // Member: mbr_bl_y
  cdr << ros_message.mbr_bl_y;

  // Member: mbr_bl_z
  cdr << ros_message.mbr_bl_z;

  // Member: mbr_tr_x
  cdr << ros_message.mbr_tr_x;

  // Member: mbr_tr_y
  cdr << ros_message.mbr_tr_y;

  // Member: mbr_tr_z
  cdr << ros_message.mbr_tr_z;

  // Member: facing
  cdr << ros_message.facing;

  // Member: lightstate
  cdr << ros_message.lightstate;

  // Member: signmain_val0
  cdr << ros_message.signmain_val0;

  // Member: signmain_val1
  cdr << ros_message.signmain_val1;

  // Member: signsuppl1_val0
  cdr << ros_message.signsuppl1_val0;

  // Member: signsuppl1_val1
  cdr << ros_message.signsuppl1_val1;

  // Member: signsuppl2_val0
  cdr << ros_message.signsuppl2_val0;

  // Member: signsuppl2_val1
  cdr << ros_message.signsuppl2_val1;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
get_serialized_size_key(
  const camera_msgs::msg::CameraDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: objid
  {
    size_t item_size = sizeof(ros_message.objid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: objecttype
  {
    size_t item_size = sizeof(ros_message.objecttype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: nvispixels
  {
    size_t item_size = sizeof(ros_message.nvispixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: confidence
  {
    size_t item_size = sizeof(ros_message.confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_bl_x
  {
    size_t item_size = sizeof(ros_message.mbr_bl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_bl_y
  {
    size_t item_size = sizeof(ros_message.mbr_bl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_bl_z
  {
    size_t item_size = sizeof(ros_message.mbr_bl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_tr_x
  {
    size_t item_size = sizeof(ros_message.mbr_tr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_tr_y
  {
    size_t item_size = sizeof(ros_message.mbr_tr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: mbr_tr_z
  {
    size_t item_size = sizeof(ros_message.mbr_tr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: facing
  {
    size_t item_size = sizeof(ros_message.facing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: lightstate
  {
    size_t item_size = sizeof(ros_message.lightstate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signmain_val0
  {
    size_t item_size = sizeof(ros_message.signmain_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signmain_val1
  {
    size_t item_size = sizeof(ros_message.signmain_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl1_val0
  {
    size_t item_size = sizeof(ros_message.signsuppl1_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl1_val1
  {
    size_t item_size = sizeof(ros_message.signsuppl1_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl2_val0
  {
    size_t item_size = sizeof(ros_message.signsuppl2_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: signsuppl2_val1
  {
    size_t item_size = sizeof(ros_message.signsuppl2_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera_msgs
max_serialized_size_key_CameraDetection(
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

  // Member: objid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: objecttype
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: nvispixels
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mbr_bl_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mbr_bl_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mbr_bl_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mbr_tr_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mbr_tr_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: mbr_tr_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: facing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: lightstate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: signmain_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: signmain_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: signsuppl1_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: signsuppl1_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: signsuppl2_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: signsuppl2_val1
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
    using DataType = camera_msgs::msg::CameraDetection;
    is_plain =
      (
      offsetof(DataType, signsuppl2_val1) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _CameraDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const camera_msgs::msg::CameraDetection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CameraDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<camera_msgs::msg::CameraDetection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CameraDetection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const camera_msgs::msg::CameraDetection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CameraDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CameraDetection(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CameraDetection__callbacks = {
  "camera_msgs::msg",
  "CameraDetection",
  _CameraDetection__cdr_serialize,
  _CameraDetection__cdr_deserialize,
  _CameraDetection__get_serialized_size,
  _CameraDetection__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CameraDetection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CameraDetection__callbacks,
  get_message_typesupport_handle_function,
  &camera_msgs__msg__CameraDetection__get_type_hash,
  &camera_msgs__msg__CameraDetection__get_type_description,
  &camera_msgs__msg__CameraDetection__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace camera_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_camera_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<camera_msgs::msg::CameraDetection>()
{
  return &camera_msgs::msg::typesupport_fastrtps_cpp::_CameraDetection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, camera_msgs, msg, CameraDetection)() {
  return &camera_msgs::msg::typesupport_fastrtps_cpp::_CameraDetection__handle;
}

#ifdef __cplusplus
}
#endif
