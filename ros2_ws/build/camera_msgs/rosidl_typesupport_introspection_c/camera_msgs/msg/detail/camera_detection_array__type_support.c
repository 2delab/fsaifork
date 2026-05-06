// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "camera_msgs/msg/detail/camera_detection_array__rosidl_typesupport_introspection_c.h"
#include "camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "camera_msgs/msg/detail/camera_detection_array__functions.h"
#include "camera_msgs/msg/detail/camera_detection_array__struct.h"


// Include directives for member types
// Member `detections`
#include "camera_msgs/msg/camera_detection.h"
// Member `detections`
#include "camera_msgs/msg/detail/camera_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  camera_msgs__msg__CameraDetectionArray__init(message_memory);
}

void camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_fini_function(void * message_memory)
{
  camera_msgs__msg__CameraDetectionArray__fini(message_memory);
}

size_t camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__size_function__CameraDetectionArray__detections(
  const void * untyped_member)
{
  const camera_msgs__msg__CameraDetection__Sequence * member =
    (const camera_msgs__msg__CameraDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__get_const_function__CameraDetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const camera_msgs__msg__CameraDetection__Sequence * member =
    (const camera_msgs__msg__CameraDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__get_function__CameraDetectionArray__detections(
  void * untyped_member, size_t index)
{
  camera_msgs__msg__CameraDetection__Sequence * member =
    (camera_msgs__msg__CameraDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__fetch_function__CameraDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const camera_msgs__msg__CameraDetection * item =
    ((const camera_msgs__msg__CameraDetection *)
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__get_const_function__CameraDetectionArray__detections(untyped_member, index));
  camera_msgs__msg__CameraDetection * value =
    (camera_msgs__msg__CameraDetection *)(untyped_value);
  *value = *item;
}

void camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__assign_function__CameraDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  camera_msgs__msg__CameraDetection * item =
    ((camera_msgs__msg__CameraDetection *)
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__get_function__CameraDetectionArray__detections(untyped_member, index));
  const camera_msgs__msg__CameraDetection * value =
    (const camera_msgs__msg__CameraDetection *)(untyped_value);
  *item = *value;
}

bool camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__resize_function__CameraDetectionArray__detections(
  void * untyped_member, size_t size)
{
  camera_msgs__msg__CameraDetection__Sequence * member =
    (camera_msgs__msg__CameraDetection__Sequence *)(untyped_member);
  camera_msgs__msg__CameraDetection__Sequence__fini(member);
  return camera_msgs__msg__CameraDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_member_array[1] = {
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera_msgs__msg__CameraDetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__size_function__CameraDetectionArray__detections,  // size() function pointer
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__get_const_function__CameraDetectionArray__detections,  // get_const(index) function pointer
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__get_function__CameraDetectionArray__detections,  // get(index) function pointer
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__fetch_function__CameraDetectionArray__detections,  // fetch(index, &value) function pointer
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__assign_function__CameraDetectionArray__detections,  // assign(index, value) function pointer
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__resize_function__CameraDetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_members = {
  "camera_msgs__msg",  // message namespace
  "CameraDetectionArray",  // message name
  1,  // number of fields
  sizeof(camera_msgs__msg__CameraDetectionArray),
  false,  // has_any_key_member_
  camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_member_array,  // message members
  camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_type_support_handle = {
  0,
  &camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_members,
  get_message_typesupport_handle_function,
  &camera_msgs__msg__CameraDetectionArray__get_type_hash,
  &camera_msgs__msg__CameraDetectionArray__get_type_description,
  &camera_msgs__msg__CameraDetectionArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, camera_msgs, msg, CameraDetectionArray)() {
  camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, camera_msgs, msg, CameraDetection)();
  if (!camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_type_support_handle.typesupport_identifier) {
    camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &camera_msgs__msg__CameraDetectionArray__rosidl_typesupport_introspection_c__CameraDetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
