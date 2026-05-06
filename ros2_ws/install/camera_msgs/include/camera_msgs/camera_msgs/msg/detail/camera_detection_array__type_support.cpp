// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "camera_msgs/msg/detail/camera_detection_array__functions.h"
#include "camera_msgs/msg/detail/camera_detection_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace camera_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CameraDetectionArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) camera_msgs::msg::CameraDetectionArray(_init);
}

void CameraDetectionArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<camera_msgs::msg::CameraDetectionArray *>(message_memory);
  typed_message->~CameraDetectionArray();
}

size_t size_function__CameraDetectionArray__detections(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<camera_msgs::msg::CameraDetection> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraDetectionArray__detections(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<camera_msgs::msg::CameraDetection> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraDetectionArray__detections(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<camera_msgs::msg::CameraDetection> *>(untyped_member);
  return &member[index];
}

void fetch_function__CameraDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const camera_msgs::msg::CameraDetection *>(
    get_const_function__CameraDetectionArray__detections(untyped_member, index));
  auto & value = *reinterpret_cast<camera_msgs::msg::CameraDetection *>(untyped_value);
  value = item;
}

void assign_function__CameraDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<camera_msgs::msg::CameraDetection *>(
    get_function__CameraDetectionArray__detections(untyped_member, index));
  const auto & value = *reinterpret_cast<const camera_msgs::msg::CameraDetection *>(untyped_value);
  item = value;
}

void resize_function__CameraDetectionArray__detections(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<camera_msgs::msg::CameraDetection> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CameraDetectionArray_message_member_array[1] = {
  {
    "detections",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<camera_msgs::msg::CameraDetection>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera_msgs::msg::CameraDetectionArray, detections),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraDetectionArray__detections,  // size() function pointer
    get_const_function__CameraDetectionArray__detections,  // get_const(index) function pointer
    get_function__CameraDetectionArray__detections,  // get(index) function pointer
    fetch_function__CameraDetectionArray__detections,  // fetch(index, &value) function pointer
    assign_function__CameraDetectionArray__detections,  // assign(index, value) function pointer
    resize_function__CameraDetectionArray__detections  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CameraDetectionArray_message_members = {
  "camera_msgs::msg",  // message namespace
  "CameraDetectionArray",  // message name
  1,  // number of fields
  sizeof(camera_msgs::msg::CameraDetectionArray),
  false,  // has_any_key_member_
  CameraDetectionArray_message_member_array,  // message members
  CameraDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CameraDetectionArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CameraDetectionArray_message_members,
  get_message_typesupport_handle_function,
  &camera_msgs__msg__CameraDetectionArray__get_type_hash,
  &camera_msgs__msg__CameraDetectionArray__get_type_description,
  &camera_msgs__msg__CameraDetectionArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace camera_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<camera_msgs::msg::CameraDetectionArray>()
{
  return &::camera_msgs::msg::rosidl_typesupport_introspection_cpp::CameraDetectionArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, camera_msgs, msg, CameraDetectionArray)() {
  return &::camera_msgs::msg::rosidl_typesupport_introspection_cpp::CameraDetectionArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
