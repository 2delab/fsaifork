// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice
#include "camera_msgs/msg/detail/camera_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
camera_msgs__msg__CameraDetection__init(camera_msgs__msg__CameraDetection * msg)
{
  if (!msg) {
    return false;
  }
  // objid
  // objecttype
  // nvispixels
  // confidence
  // mbr_bl_x
  // mbr_bl_y
  // mbr_bl_z
  // mbr_tr_x
  // mbr_tr_y
  // mbr_tr_z
  // facing
  // lightstate
  // signmain_val0
  // signmain_val1
  // signsuppl1_val0
  // signsuppl1_val1
  // signsuppl2_val0
  // signsuppl2_val1
  return true;
}

void
camera_msgs__msg__CameraDetection__fini(camera_msgs__msg__CameraDetection * msg)
{
  if (!msg) {
    return;
  }
  // objid
  // objecttype
  // nvispixels
  // confidence
  // mbr_bl_x
  // mbr_bl_y
  // mbr_bl_z
  // mbr_tr_x
  // mbr_tr_y
  // mbr_tr_z
  // facing
  // lightstate
  // signmain_val0
  // signmain_val1
  // signsuppl1_val0
  // signsuppl1_val1
  // signsuppl2_val0
  // signsuppl2_val1
}

bool
camera_msgs__msg__CameraDetection__are_equal(const camera_msgs__msg__CameraDetection * lhs, const camera_msgs__msg__CameraDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // objid
  if (lhs->objid != rhs->objid) {
    return false;
  }
  // objecttype
  if (lhs->objecttype != rhs->objecttype) {
    return false;
  }
  // nvispixels
  if (lhs->nvispixels != rhs->nvispixels) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // mbr_bl_x
  if (lhs->mbr_bl_x != rhs->mbr_bl_x) {
    return false;
  }
  // mbr_bl_y
  if (lhs->mbr_bl_y != rhs->mbr_bl_y) {
    return false;
  }
  // mbr_bl_z
  if (lhs->mbr_bl_z != rhs->mbr_bl_z) {
    return false;
  }
  // mbr_tr_x
  if (lhs->mbr_tr_x != rhs->mbr_tr_x) {
    return false;
  }
  // mbr_tr_y
  if (lhs->mbr_tr_y != rhs->mbr_tr_y) {
    return false;
  }
  // mbr_tr_z
  if (lhs->mbr_tr_z != rhs->mbr_tr_z) {
    return false;
  }
  // facing
  if (lhs->facing != rhs->facing) {
    return false;
  }
  // lightstate
  if (lhs->lightstate != rhs->lightstate) {
    return false;
  }
  // signmain_val0
  if (lhs->signmain_val0 != rhs->signmain_val0) {
    return false;
  }
  // signmain_val1
  if (lhs->signmain_val1 != rhs->signmain_val1) {
    return false;
  }
  // signsuppl1_val0
  if (lhs->signsuppl1_val0 != rhs->signsuppl1_val0) {
    return false;
  }
  // signsuppl1_val1
  if (lhs->signsuppl1_val1 != rhs->signsuppl1_val1) {
    return false;
  }
  // signsuppl2_val0
  if (lhs->signsuppl2_val0 != rhs->signsuppl2_val0) {
    return false;
  }
  // signsuppl2_val1
  if (lhs->signsuppl2_val1 != rhs->signsuppl2_val1) {
    return false;
  }
  return true;
}

bool
camera_msgs__msg__CameraDetection__copy(
  const camera_msgs__msg__CameraDetection * input,
  camera_msgs__msg__CameraDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // objid
  output->objid = input->objid;
  // objecttype
  output->objecttype = input->objecttype;
  // nvispixels
  output->nvispixels = input->nvispixels;
  // confidence
  output->confidence = input->confidence;
  // mbr_bl_x
  output->mbr_bl_x = input->mbr_bl_x;
  // mbr_bl_y
  output->mbr_bl_y = input->mbr_bl_y;
  // mbr_bl_z
  output->mbr_bl_z = input->mbr_bl_z;
  // mbr_tr_x
  output->mbr_tr_x = input->mbr_tr_x;
  // mbr_tr_y
  output->mbr_tr_y = input->mbr_tr_y;
  // mbr_tr_z
  output->mbr_tr_z = input->mbr_tr_z;
  // facing
  output->facing = input->facing;
  // lightstate
  output->lightstate = input->lightstate;
  // signmain_val0
  output->signmain_val0 = input->signmain_val0;
  // signmain_val1
  output->signmain_val1 = input->signmain_val1;
  // signsuppl1_val0
  output->signsuppl1_val0 = input->signsuppl1_val0;
  // signsuppl1_val1
  output->signsuppl1_val1 = input->signsuppl1_val1;
  // signsuppl2_val0
  output->signsuppl2_val0 = input->signsuppl2_val0;
  // signsuppl2_val1
  output->signsuppl2_val1 = input->signsuppl2_val1;
  return true;
}

camera_msgs__msg__CameraDetection *
camera_msgs__msg__CameraDetection__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_msgs__msg__CameraDetection * msg = (camera_msgs__msg__CameraDetection *)allocator.allocate(sizeof(camera_msgs__msg__CameraDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera_msgs__msg__CameraDetection));
  bool success = camera_msgs__msg__CameraDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera_msgs__msg__CameraDetection__destroy(camera_msgs__msg__CameraDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera_msgs__msg__CameraDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera_msgs__msg__CameraDetection__Sequence__init(camera_msgs__msg__CameraDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_msgs__msg__CameraDetection * data = NULL;

  if (size) {
    data = (camera_msgs__msg__CameraDetection *)allocator.zero_allocate(size, sizeof(camera_msgs__msg__CameraDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera_msgs__msg__CameraDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera_msgs__msg__CameraDetection__fini(&data[i - 1]);
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
camera_msgs__msg__CameraDetection__Sequence__fini(camera_msgs__msg__CameraDetection__Sequence * array)
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
      camera_msgs__msg__CameraDetection__fini(&array->data[i]);
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

camera_msgs__msg__CameraDetection__Sequence *
camera_msgs__msg__CameraDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_msgs__msg__CameraDetection__Sequence * array = (camera_msgs__msg__CameraDetection__Sequence *)allocator.allocate(sizeof(camera_msgs__msg__CameraDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera_msgs__msg__CameraDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera_msgs__msg__CameraDetection__Sequence__destroy(camera_msgs__msg__CameraDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera_msgs__msg__CameraDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera_msgs__msg__CameraDetection__Sequence__are_equal(const camera_msgs__msg__CameraDetection__Sequence * lhs, const camera_msgs__msg__CameraDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera_msgs__msg__CameraDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera_msgs__msg__CameraDetection__Sequence__copy(
  const camera_msgs__msg__CameraDetection__Sequence * input,
  camera_msgs__msg__CameraDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera_msgs__msg__CameraDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera_msgs__msg__CameraDetection * data =
      (camera_msgs__msg__CameraDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera_msgs__msg__CameraDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera_msgs__msg__CameraDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera_msgs__msg__CameraDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
