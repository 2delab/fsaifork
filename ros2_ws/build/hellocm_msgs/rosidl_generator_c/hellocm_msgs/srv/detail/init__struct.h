// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hellocm_msgs/srv/init.h"


#ifndef HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_H_
#define HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Init in the package hellocm_msgs.
typedef struct hellocm_msgs__srv__Init_Request
{
  rosidl_runtime_c__String message;
} hellocm_msgs__srv__Init_Request;

// Struct for a sequence of hellocm_msgs__srv__Init_Request.
typedef struct hellocm_msgs__srv__Init_Request__Sequence
{
  hellocm_msgs__srv__Init_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__srv__Init_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Init in the package hellocm_msgs.
typedef struct hellocm_msgs__srv__Init_Response
{
  /// indicate successful run of triggered service
  bool success;
  /// default cycle time in ms
  int32_t cycletime;
  /// informational, e.g. for error messages
  rosidl_runtime_c__String message;
} hellocm_msgs__srv__Init_Response;

// Struct for a sequence of hellocm_msgs__srv__Init_Response.
typedef struct hellocm_msgs__srv__Init_Response__Sequence
{
  hellocm_msgs__srv__Init_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__srv__Init_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  hellocm_msgs__srv__Init_Event__request__MAX_SIZE = 1
};
// response
enum
{
  hellocm_msgs__srv__Init_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Init in the package hellocm_msgs.
typedef struct hellocm_msgs__srv__Init_Event
{
  service_msgs__msg__ServiceEventInfo info;
  hellocm_msgs__srv__Init_Request__Sequence request;
  hellocm_msgs__srv__Init_Response__Sequence response;
} hellocm_msgs__srv__Init_Event;

// Struct for a sequence of hellocm_msgs__srv__Init_Event.
typedef struct hellocm_msgs__srv__Init_Event__Sequence
{
  hellocm_msgs__srv__Init_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hellocm_msgs__srv__Init_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOCM_MSGS__SRV__DETAIL__INIT__STRUCT_H_
