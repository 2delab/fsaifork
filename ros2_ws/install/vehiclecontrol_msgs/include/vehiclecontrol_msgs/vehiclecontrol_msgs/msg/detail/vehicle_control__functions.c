// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice
#include "vehiclecontrol_msgs/msg/detail/vehicle_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vehiclecontrol_msgs__msg__VehicleControl__init(vehiclecontrol_msgs__msg__VehicleControl * msg)
{
  if (!msg) {
    return false;
  }
  // use_vc
  // selector_ctrl
  // gas
  // brake
  // steer_ang
  // steer_ang_vel
  // steer_ang_acc
  return true;
}

void
vehiclecontrol_msgs__msg__VehicleControl__fini(vehiclecontrol_msgs__msg__VehicleControl * msg)
{
  if (!msg) {
    return;
  }
  // use_vc
  // selector_ctrl
  // gas
  // brake
  // steer_ang
  // steer_ang_vel
  // steer_ang_acc
}

bool
vehiclecontrol_msgs__msg__VehicleControl__are_equal(const vehiclecontrol_msgs__msg__VehicleControl * lhs, const vehiclecontrol_msgs__msg__VehicleControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // use_vc
  if (lhs->use_vc != rhs->use_vc) {
    return false;
  }
  // selector_ctrl
  if (lhs->selector_ctrl != rhs->selector_ctrl) {
    return false;
  }
  // gas
  if (lhs->gas != rhs->gas) {
    return false;
  }
  // brake
  if (lhs->brake != rhs->brake) {
    return false;
  }
  // steer_ang
  if (lhs->steer_ang != rhs->steer_ang) {
    return false;
  }
  // steer_ang_vel
  if (lhs->steer_ang_vel != rhs->steer_ang_vel) {
    return false;
  }
  // steer_ang_acc
  if (lhs->steer_ang_acc != rhs->steer_ang_acc) {
    return false;
  }
  return true;
}

bool
vehiclecontrol_msgs__msg__VehicleControl__copy(
  const vehiclecontrol_msgs__msg__VehicleControl * input,
  vehiclecontrol_msgs__msg__VehicleControl * output)
{
  if (!input || !output) {
    return false;
  }
  // use_vc
  output->use_vc = input->use_vc;
  // selector_ctrl
  output->selector_ctrl = input->selector_ctrl;
  // gas
  output->gas = input->gas;
  // brake
  output->brake = input->brake;
  // steer_ang
  output->steer_ang = input->steer_ang;
  // steer_ang_vel
  output->steer_ang_vel = input->steer_ang_vel;
  // steer_ang_acc
  output->steer_ang_acc = input->steer_ang_acc;
  return true;
}

vehiclecontrol_msgs__msg__VehicleControl *
vehiclecontrol_msgs__msg__VehicleControl__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehiclecontrol_msgs__msg__VehicleControl * msg = (vehiclecontrol_msgs__msg__VehicleControl *)allocator.allocate(sizeof(vehiclecontrol_msgs__msg__VehicleControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehiclecontrol_msgs__msg__VehicleControl));
  bool success = vehiclecontrol_msgs__msg__VehicleControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehiclecontrol_msgs__msg__VehicleControl__destroy(vehiclecontrol_msgs__msg__VehicleControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehiclecontrol_msgs__msg__VehicleControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehiclecontrol_msgs__msg__VehicleControl__Sequence__init(vehiclecontrol_msgs__msg__VehicleControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehiclecontrol_msgs__msg__VehicleControl * data = NULL;

  if (size) {
    data = (vehiclecontrol_msgs__msg__VehicleControl *)allocator.zero_allocate(size, sizeof(vehiclecontrol_msgs__msg__VehicleControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehiclecontrol_msgs__msg__VehicleControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehiclecontrol_msgs__msg__VehicleControl__fini(&data[i - 1]);
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
vehiclecontrol_msgs__msg__VehicleControl__Sequence__fini(vehiclecontrol_msgs__msg__VehicleControl__Sequence * array)
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
      vehiclecontrol_msgs__msg__VehicleControl__fini(&array->data[i]);
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

vehiclecontrol_msgs__msg__VehicleControl__Sequence *
vehiclecontrol_msgs__msg__VehicleControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehiclecontrol_msgs__msg__VehicleControl__Sequence * array = (vehiclecontrol_msgs__msg__VehicleControl__Sequence *)allocator.allocate(sizeof(vehiclecontrol_msgs__msg__VehicleControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehiclecontrol_msgs__msg__VehicleControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehiclecontrol_msgs__msg__VehicleControl__Sequence__destroy(vehiclecontrol_msgs__msg__VehicleControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehiclecontrol_msgs__msg__VehicleControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehiclecontrol_msgs__msg__VehicleControl__Sequence__are_equal(const vehiclecontrol_msgs__msg__VehicleControl__Sequence * lhs, const vehiclecontrol_msgs__msg__VehicleControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehiclecontrol_msgs__msg__VehicleControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehiclecontrol_msgs__msg__VehicleControl__Sequence__copy(
  const vehiclecontrol_msgs__msg__VehicleControl__Sequence * input,
  vehiclecontrol_msgs__msg__VehicleControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehiclecontrol_msgs__msg__VehicleControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehiclecontrol_msgs__msg__VehicleControl * data =
      (vehiclecontrol_msgs__msg__VehicleControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehiclecontrol_msgs__msg__VehicleControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehiclecontrol_msgs__msg__VehicleControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehiclecontrol_msgs__msg__VehicleControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
