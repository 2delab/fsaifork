// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection_array.h"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__FUNCTIONS_H_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "camera_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "camera_msgs/msg/detail/camera_detection_array__struct.h"

/// Initialize msg/CameraDetectionArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * camera_msgs__msg__CameraDetectionArray
 * )) before or use
 * camera_msgs__msg__CameraDetectionArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
bool
camera_msgs__msg__CameraDetectionArray__init(camera_msgs__msg__CameraDetectionArray * msg);

/// Finalize msg/CameraDetectionArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
void
camera_msgs__msg__CameraDetectionArray__fini(camera_msgs__msg__CameraDetectionArray * msg);

/// Create msg/CameraDetectionArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * camera_msgs__msg__CameraDetectionArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
camera_msgs__msg__CameraDetectionArray *
camera_msgs__msg__CameraDetectionArray__create(void);

/// Destroy msg/CameraDetectionArray message.
/**
 * It calls
 * camera_msgs__msg__CameraDetectionArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
void
camera_msgs__msg__CameraDetectionArray__destroy(camera_msgs__msg__CameraDetectionArray * msg);

/// Check for msg/CameraDetectionArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
bool
camera_msgs__msg__CameraDetectionArray__are_equal(const camera_msgs__msg__CameraDetectionArray * lhs, const camera_msgs__msg__CameraDetectionArray * rhs);

/// Copy a msg/CameraDetectionArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
bool
camera_msgs__msg__CameraDetectionArray__copy(
  const camera_msgs__msg__CameraDetectionArray * input,
  camera_msgs__msg__CameraDetectionArray * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
const rosidl_type_hash_t *
camera_msgs__msg__CameraDetectionArray__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
const rosidl_runtime_c__type_description__TypeDescription *
camera_msgs__msg__CameraDetectionArray__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
const rosidl_runtime_c__type_description__TypeSource *
camera_msgs__msg__CameraDetectionArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
camera_msgs__msg__CameraDetectionArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/CameraDetectionArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * camera_msgs__msg__CameraDetectionArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
bool
camera_msgs__msg__CameraDetectionArray__Sequence__init(camera_msgs__msg__CameraDetectionArray__Sequence * array, size_t size);

/// Finalize array of msg/CameraDetectionArray messages.
/**
 * It calls
 * camera_msgs__msg__CameraDetectionArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
void
camera_msgs__msg__CameraDetectionArray__Sequence__fini(camera_msgs__msg__CameraDetectionArray__Sequence * array);

/// Create array of msg/CameraDetectionArray messages.
/**
 * It allocates the memory for the array and calls
 * camera_msgs__msg__CameraDetectionArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
camera_msgs__msg__CameraDetectionArray__Sequence *
camera_msgs__msg__CameraDetectionArray__Sequence__create(size_t size);

/// Destroy array of msg/CameraDetectionArray messages.
/**
 * It calls
 * camera_msgs__msg__CameraDetectionArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
void
camera_msgs__msg__CameraDetectionArray__Sequence__destroy(camera_msgs__msg__CameraDetectionArray__Sequence * array);

/// Check for msg/CameraDetectionArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
bool
camera_msgs__msg__CameraDetectionArray__Sequence__are_equal(const camera_msgs__msg__CameraDetectionArray__Sequence * lhs, const camera_msgs__msg__CameraDetectionArray__Sequence * rhs);

/// Copy an array of msg/CameraDetectionArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
bool
camera_msgs__msg__CameraDetectionArray__Sequence__copy(
  const camera_msgs__msg__CameraDetectionArray__Sequence * input,
  camera_msgs__msg__CameraDetectionArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__FUNCTIONS_H_
