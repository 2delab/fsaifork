// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice
#include "camera_msgs/msg/detail/camera_detection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "camera_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "camera_msgs/msg/detail/camera_detection__struct.h"
#include "camera_msgs/msg/detail/camera_detection__functions.h"
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


using _CameraDetection__ros_msg_type = camera_msgs__msg__CameraDetection;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
bool cdr_serialize_camera_msgs__msg__CameraDetection(
  const camera_msgs__msg__CameraDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: objid
  {
    cdr << ros_message->objid;
  }

  // Field name: objecttype
  {
    cdr << ros_message->objecttype;
  }

  // Field name: nvispixels
  {
    cdr << ros_message->nvispixels;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: mbr_bl_x
  {
    cdr << ros_message->mbr_bl_x;
  }

  // Field name: mbr_bl_y
  {
    cdr << ros_message->mbr_bl_y;
  }

  // Field name: mbr_bl_z
  {
    cdr << ros_message->mbr_bl_z;
  }

  // Field name: mbr_tr_x
  {
    cdr << ros_message->mbr_tr_x;
  }

  // Field name: mbr_tr_y
  {
    cdr << ros_message->mbr_tr_y;
  }

  // Field name: mbr_tr_z
  {
    cdr << ros_message->mbr_tr_z;
  }

  // Field name: facing
  {
    cdr << ros_message->facing;
  }

  // Field name: lightstate
  {
    cdr << ros_message->lightstate;
  }

  // Field name: signmain_val0
  {
    cdr << ros_message->signmain_val0;
  }

  // Field name: signmain_val1
  {
    cdr << ros_message->signmain_val1;
  }

  // Field name: signsuppl1_val0
  {
    cdr << ros_message->signsuppl1_val0;
  }

  // Field name: signsuppl1_val1
  {
    cdr << ros_message->signsuppl1_val1;
  }

  // Field name: signsuppl2_val0
  {
    cdr << ros_message->signsuppl2_val0;
  }

  // Field name: signsuppl2_val1
  {
    cdr << ros_message->signsuppl2_val1;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
bool cdr_deserialize_camera_msgs__msg__CameraDetection(
  eprosima::fastcdr::Cdr & cdr,
  camera_msgs__msg__CameraDetection * ros_message)
{
  // Field name: objid
  {
    cdr >> ros_message->objid;
  }

  // Field name: objecttype
  {
    cdr >> ros_message->objecttype;
  }

  // Field name: nvispixels
  {
    cdr >> ros_message->nvispixels;
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: mbr_bl_x
  {
    cdr >> ros_message->mbr_bl_x;
  }

  // Field name: mbr_bl_y
  {
    cdr >> ros_message->mbr_bl_y;
  }

  // Field name: mbr_bl_z
  {
    cdr >> ros_message->mbr_bl_z;
  }

  // Field name: mbr_tr_x
  {
    cdr >> ros_message->mbr_tr_x;
  }

  // Field name: mbr_tr_y
  {
    cdr >> ros_message->mbr_tr_y;
  }

  // Field name: mbr_tr_z
  {
    cdr >> ros_message->mbr_tr_z;
  }

  // Field name: facing
  {
    cdr >> ros_message->facing;
  }

  // Field name: lightstate
  {
    cdr >> ros_message->lightstate;
  }

  // Field name: signmain_val0
  {
    cdr >> ros_message->signmain_val0;
  }

  // Field name: signmain_val1
  {
    cdr >> ros_message->signmain_val1;
  }

  // Field name: signsuppl1_val0
  {
    cdr >> ros_message->signsuppl1_val0;
  }

  // Field name: signsuppl1_val1
  {
    cdr >> ros_message->signsuppl1_val1;
  }

  // Field name: signsuppl2_val0
  {
    cdr >> ros_message->signsuppl2_val0;
  }

  // Field name: signsuppl2_val1
  {
    cdr >> ros_message->signsuppl2_val1;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t get_serialized_size_camera_msgs__msg__CameraDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CameraDetection__ros_msg_type * ros_message = static_cast<const _CameraDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: objid
  {
    size_t item_size = sizeof(ros_message->objid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: objecttype
  {
    size_t item_size = sizeof(ros_message->objecttype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: nvispixels
  {
    size_t item_size = sizeof(ros_message->nvispixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_bl_x
  {
    size_t item_size = sizeof(ros_message->mbr_bl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_bl_y
  {
    size_t item_size = sizeof(ros_message->mbr_bl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_bl_z
  {
    size_t item_size = sizeof(ros_message->mbr_bl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_tr_x
  {
    size_t item_size = sizeof(ros_message->mbr_tr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_tr_y
  {
    size_t item_size = sizeof(ros_message->mbr_tr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_tr_z
  {
    size_t item_size = sizeof(ros_message->mbr_tr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: facing
  {
    size_t item_size = sizeof(ros_message->facing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: lightstate
  {
    size_t item_size = sizeof(ros_message->lightstate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signmain_val0
  {
    size_t item_size = sizeof(ros_message->signmain_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signmain_val1
  {
    size_t item_size = sizeof(ros_message->signmain_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl1_val0
  {
    size_t item_size = sizeof(ros_message->signsuppl1_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl1_val1
  {
    size_t item_size = sizeof(ros_message->signsuppl1_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl2_val0
  {
    size_t item_size = sizeof(ros_message->signsuppl2_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl2_val1
  {
    size_t item_size = sizeof(ros_message->signsuppl2_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t max_serialized_size_camera_msgs__msg__CameraDetection(
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

  // Field name: objid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: objecttype
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: nvispixels
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_bl_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_bl_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_bl_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_tr_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_tr_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_tr_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: facing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: lightstate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: signmain_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signmain_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl1_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl1_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl2_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl2_val1
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
    using DataType = camera_msgs__msg__CameraDetection;
    is_plain =
      (
      offsetof(DataType, signsuppl2_val1) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
bool cdr_serialize_key_camera_msgs__msg__CameraDetection(
  const camera_msgs__msg__CameraDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: objid
  {
    cdr << ros_message->objid;
  }

  // Field name: objecttype
  {
    cdr << ros_message->objecttype;
  }

  // Field name: nvispixels
  {
    cdr << ros_message->nvispixels;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: mbr_bl_x
  {
    cdr << ros_message->mbr_bl_x;
  }

  // Field name: mbr_bl_y
  {
    cdr << ros_message->mbr_bl_y;
  }

  // Field name: mbr_bl_z
  {
    cdr << ros_message->mbr_bl_z;
  }

  // Field name: mbr_tr_x
  {
    cdr << ros_message->mbr_tr_x;
  }

  // Field name: mbr_tr_y
  {
    cdr << ros_message->mbr_tr_y;
  }

  // Field name: mbr_tr_z
  {
    cdr << ros_message->mbr_tr_z;
  }

  // Field name: facing
  {
    cdr << ros_message->facing;
  }

  // Field name: lightstate
  {
    cdr << ros_message->lightstate;
  }

  // Field name: signmain_val0
  {
    cdr << ros_message->signmain_val0;
  }

  // Field name: signmain_val1
  {
    cdr << ros_message->signmain_val1;
  }

  // Field name: signsuppl1_val0
  {
    cdr << ros_message->signsuppl1_val0;
  }

  // Field name: signsuppl1_val1
  {
    cdr << ros_message->signsuppl1_val1;
  }

  // Field name: signsuppl2_val0
  {
    cdr << ros_message->signsuppl2_val0;
  }

  // Field name: signsuppl2_val1
  {
    cdr << ros_message->signsuppl2_val1;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t get_serialized_size_key_camera_msgs__msg__CameraDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CameraDetection__ros_msg_type * ros_message = static_cast<const _CameraDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: objid
  {
    size_t item_size = sizeof(ros_message->objid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: objecttype
  {
    size_t item_size = sizeof(ros_message->objecttype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: nvispixels
  {
    size_t item_size = sizeof(ros_message->nvispixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_bl_x
  {
    size_t item_size = sizeof(ros_message->mbr_bl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_bl_y
  {
    size_t item_size = sizeof(ros_message->mbr_bl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_bl_z
  {
    size_t item_size = sizeof(ros_message->mbr_bl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_tr_x
  {
    size_t item_size = sizeof(ros_message->mbr_tr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_tr_y
  {
    size_t item_size = sizeof(ros_message->mbr_tr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mbr_tr_z
  {
    size_t item_size = sizeof(ros_message->mbr_tr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: facing
  {
    size_t item_size = sizeof(ros_message->facing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: lightstate
  {
    size_t item_size = sizeof(ros_message->lightstate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signmain_val0
  {
    size_t item_size = sizeof(ros_message->signmain_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signmain_val1
  {
    size_t item_size = sizeof(ros_message->signmain_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl1_val0
  {
    size_t item_size = sizeof(ros_message->signsuppl1_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl1_val1
  {
    size_t item_size = sizeof(ros_message->signsuppl1_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl2_val0
  {
    size_t item_size = sizeof(ros_message->signsuppl2_val0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: signsuppl2_val1
  {
    size_t item_size = sizeof(ros_message->signsuppl2_val1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera_msgs
size_t max_serialized_size_key_camera_msgs__msg__CameraDetection(
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
  // Field name: objid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: objecttype
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: nvispixels
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_bl_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_bl_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_bl_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_tr_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_tr_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: mbr_tr_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: facing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: lightstate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: signmain_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signmain_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl1_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl1_val1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl2_val0
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: signsuppl2_val1
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
    using DataType = camera_msgs__msg__CameraDetection;
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
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const camera_msgs__msg__CameraDetection * ros_message = static_cast<const camera_msgs__msg__CameraDetection *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_camera_msgs__msg__CameraDetection(ros_message, cdr);
}

static bool _CameraDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  camera_msgs__msg__CameraDetection * ros_message = static_cast<camera_msgs__msg__CameraDetection *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_camera_msgs__msg__CameraDetection(cdr, ros_message);
}

static uint32_t _CameraDetection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_camera_msgs__msg__CameraDetection(
      untyped_ros_message, 0));
}

static size_t _CameraDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_camera_msgs__msg__CameraDetection(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CameraDetection = {
  "camera_msgs::msg",
  "CameraDetection",
  _CameraDetection__cdr_serialize,
  _CameraDetection__cdr_deserialize,
  _CameraDetection__get_serialized_size,
  _CameraDetection__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CameraDetection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CameraDetection,
  get_message_typesupport_handle_function,
  &camera_msgs__msg__CameraDetection__get_type_hash,
  &camera_msgs__msg__CameraDetection__get_type_description,
  &camera_msgs__msg__CameraDetection__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, camera_msgs, msg, CameraDetection)() {
  return &_CameraDetection__type_support;
}

#if defined(__cplusplus)
}
#endif
