// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:msg/Ext2CM.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hellocm_msgs/msg/ext2_cm.h"


#ifndef HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__STRUCT_H_
#define HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/Ext2CM in the package hellocm_msgs.
/**
  * Message from external ROS Node to CarMaker ROS Node
 */
typedef struct hellocm_msgs__msg__Ext2CM
{
  /// General ROS Header (optional)
  std_msgs__msg__Header header;
  /// ROS time when message was sent (optional)
  builtin_interfaces__msg__Time time;
  /// Cycle number since simulation start (optional)
  int64_t cycleno;
} hellocm_msgs__msg__Ext2CM;

// Struct for a sequence of hellocm_msgs__msg__Ext2CM.
typedef struct hellocm_msgs__msg__Ext2CM__Sequence
{
  hellocm_msgs__msg__Ext2CM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__msg__Ext2CM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__STRUCT_H_
