// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice
#include "camera_msgs/msg/detail/camera_detection_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `detections`
#include "camera_msgs/msg/detail/camera_detection__functions.h"

bool
camera_msgs__msg__CameraDetectionArray__init(camera_msgs__msg__CameraDetectionArray * msg)
{
  if (!msg) {
    return false;
  }
  // detections
  if (!camera_msgs__msg__CameraDetection__Sequence__init(&msg->detections, 0)) {
    camera_msgs__msg__CameraDetectionArray__fini(msg);
    return false;
  }
  return true;
}

void
camera_msgs__msg__CameraDetectionArray__fini(camera_msgs__msg__CameraDetectionArray * msg)
{
  if (!msg) {
    return;
  }
  // detections
  camera_msgs__msg__CameraDetection__Sequence__fini(&msg->detections);
}

bool
camera_msgs__msg__CameraDetectionArray__are_equal(const camera_msgs__msg__CameraDetectionArray * lhs, const camera_msgs__msg__CameraDetectionArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detections
  if (!camera_msgs__msg__CameraDetection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  return true;
}

bool
camera_msgs__msg__CameraDetectionArray__copy(
  const camera_msgs__msg__CameraDetectionArray * input,
  camera_msgs__msg__CameraDetectionArray * output)
{
  if (!input || !output) {
    return false;
  }
  // detections
  if (!camera_msgs__msg__CameraDetection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  return true;
}

camera_msgs__msg__CameraDetectionArray *
camera_msgs__msg__CameraDetectionArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_msgs__msg__CameraDetectionArray * msg = (camera_msgs__msg__CameraDetectionArray *)allocator.allocate(sizeof(camera_msgs__msg__CameraDetectionArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera_msgs__msg__CameraDetectionArray));
  bool success = camera_msgs__msg__CameraDetectionArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera_msgs__msg__CameraDetectionArray__destroy(camera_msgs__msg__CameraDetectionArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera_msgs__msg__CameraDetectionArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera_msgs__msg__CameraDetectionArray__Sequence__init(camera_msgs__msg__CameraDetectionArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_msgs__msg__CameraDetectionArray * data = NULL;

  if (size) {
    data = (camera_msgs__msg__CameraDetectionArray *)allocator.zero_allocate(size, sizeof(camera_msgs__msg__CameraDetectionArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera_msgs__msg__CameraDetectionArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera_msgs__msg__CameraDetectionArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
camera_msgs__msg__CameraDetectionArray__Sequence__fini(camera_msgs__msg__CameraDetectionArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      camera_msgs__msg__CameraDetectionArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

camera_msgs__msg__CameraDetectionArray__Sequence *
camera_msgs__msg__CameraDetectionArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_msgs__msg__CameraDetectionArray__Sequence * array = (camera_msgs__msg__CameraDetectionArray__Sequence *)allocator.allocate(sizeof(camera_msgs__msg__CameraDetectionArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera_msgs__msg__CameraDetectionArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera_msgs__msg__CameraDetectionArray__Sequence__destroy(camera_msgs__msg__CameraDetectionArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera_msgs__msg__CameraDetectionArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera_msgs__msg__CameraDetectionArray__Sequence__are_equal(const camera_msgs__msg__CameraDetectionArray__Sequence * lhs, const camera_msgs__msg__CameraDetectionArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera_msgs__msg__CameraDetectionArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera_msgs__msg__CameraDetectionArray__Sequence__copy(
  const camera_msgs__msg__CameraDetectionArray__Sequence * input,
  camera_msgs__msg__CameraDetectionArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera_msgs__msg__CameraDetectionArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera_msgs__msg__CameraDetectionArray * data =
      (camera_msgs__msg__CameraDetectionArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera_msgs__msg__CameraDetectionArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera_msgs__msg__CameraDetectionArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera_msgs__msg__CameraDetectionArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
