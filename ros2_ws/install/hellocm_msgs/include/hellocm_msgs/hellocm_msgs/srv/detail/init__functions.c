// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice
#include "hellocm_msgs/srv/detail/init__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
hellocm_msgs__srv__Init_Request__init(hellocm_msgs__srv__Init_Request * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    hellocm_msgs__srv__Init_Request__fini(msg);
    return false;
  }
  return true;
}

void
hellocm_msgs__srv__Init_Request__fini(hellocm_msgs__srv__Init_Request * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
hellocm_msgs__srv__Init_Request__are_equal(const hellocm_msgs__srv__Init_Request * lhs, const hellocm_msgs__srv__Init_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
hellocm_msgs__srv__Init_Request__copy(
  const hellocm_msgs__srv__Init_Request * input,
  hellocm_msgs__srv__Init_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

hellocm_msgs__srv__Init_Request *
hellocm_msgs__srv__Init_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Request * msg = (hellocm_msgs__srv__Init_Request *)allocator.allocate(sizeof(hellocm_msgs__srv__Init_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__srv__Init_Request));
  bool success = hellocm_msgs__srv__Init_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__srv__Init_Request__destroy(hellocm_msgs__srv__Init_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hellocm_msgs__srv__Init_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hellocm_msgs__srv__Init_Request__Sequence__init(hellocm_msgs__srv__Init_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Request * data = NULL;

  if (size) {
    data = (hellocm_msgs__srv__Init_Request *)allocator.zero_allocate(size, sizeof(hellocm_msgs__srv__Init_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__srv__Init_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__srv__Init_Request__fini(&data[i - 1]);
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
hellocm_msgs__srv__Init_Request__Sequence__fini(hellocm_msgs__srv__Init_Request__Sequence * array)
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
      hellocm_msgs__srv__Init_Request__fini(&array->data[i]);
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

hellocm_msgs__srv__Init_Request__Sequence *
hellocm_msgs__srv__Init_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Request__Sequence * array = (hellocm_msgs__srv__Init_Request__Sequence *)allocator.allocate(sizeof(hellocm_msgs__srv__Init_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__srv__Init_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__srv__Init_Request__Sequence__destroy(hellocm_msgs__srv__Init_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hellocm_msgs__srv__Init_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hellocm_msgs__srv__Init_Request__Sequence__are_equal(const hellocm_msgs__srv__Init_Request__Sequence * lhs, const hellocm_msgs__srv__Init_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__srv__Init_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__srv__Init_Request__Sequence__copy(
  const hellocm_msgs__srv__Init_Request__Sequence * input,
  hellocm_msgs__srv__Init_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__srv__Init_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hellocm_msgs__srv__Init_Request * data =
      (hellocm_msgs__srv__Init_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__srv__Init_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hellocm_msgs__srv__Init_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hellocm_msgs__srv__Init_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
hellocm_msgs__srv__Init_Response__init(hellocm_msgs__srv__Init_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // cycletime
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    hellocm_msgs__srv__Init_Response__fini(msg);
    return false;
  }
  return true;
}

void
hellocm_msgs__srv__Init_Response__fini(hellocm_msgs__srv__Init_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // cycletime
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
hellocm_msgs__srv__Init_Response__are_equal(const hellocm_msgs__srv__Init_Response * lhs, const hellocm_msgs__srv__Init_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // cycletime
  if (lhs->cycletime != rhs->cycletime) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
hellocm_msgs__srv__Init_Response__copy(
  const hellocm_msgs__srv__Init_Response * input,
  hellocm_msgs__srv__Init_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // cycletime
  output->cycletime = input->cycletime;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

hellocm_msgs__srv__Init_Response *
hellocm_msgs__srv__Init_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Response * msg = (hellocm_msgs__srv__Init_Response *)allocator.allocate(sizeof(hellocm_msgs__srv__Init_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__srv__Init_Response));
  bool success = hellocm_msgs__srv__Init_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__srv__Init_Response__destroy(hellocm_msgs__srv__Init_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hellocm_msgs__srv__Init_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hellocm_msgs__srv__Init_Response__Sequence__init(hellocm_msgs__srv__Init_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Response * data = NULL;

  if (size) {
    data = (hellocm_msgs__srv__Init_Response *)allocator.zero_allocate(size, sizeof(hellocm_msgs__srv__Init_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__srv__Init_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__srv__Init_Response__fini(&data[i - 1]);
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
hellocm_msgs__srv__Init_Response__Sequence__fini(hellocm_msgs__srv__Init_Response__Sequence * array)
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
      hellocm_msgs__srv__Init_Response__fini(&array->data[i]);
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

hellocm_msgs__srv__Init_Response__Sequence *
hellocm_msgs__srv__Init_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Response__Sequence * array = (hellocm_msgs__srv__Init_Response__Sequence *)allocator.allocate(sizeof(hellocm_msgs__srv__Init_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__srv__Init_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__srv__Init_Response__Sequence__destroy(hellocm_msgs__srv__Init_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hellocm_msgs__srv__Init_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hellocm_msgs__srv__Init_Response__Sequence__are_equal(const hellocm_msgs__srv__Init_Response__Sequence * lhs, const hellocm_msgs__srv__Init_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__srv__Init_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__srv__Init_Response__Sequence__copy(
  const hellocm_msgs__srv__Init_Response__Sequence * input,
  hellocm_msgs__srv__Init_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__srv__Init_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hellocm_msgs__srv__Init_Response * data =
      (hellocm_msgs__srv__Init_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__srv__Init_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hellocm_msgs__srv__Init_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hellocm_msgs__srv__Init_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "hellocm_msgs/srv/detail/init__functions.h"

bool
hellocm_msgs__srv__Init_Event__init(hellocm_msgs__srv__Init_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    hellocm_msgs__srv__Init_Event__fini(msg);
    return false;
  }
  // request
  if (!hellocm_msgs__srv__Init_Request__Sequence__init(&msg->request, 0)) {
    hellocm_msgs__srv__Init_Event__fini(msg);
    return false;
  }
  // response
  if (!hellocm_msgs__srv__Init_Response__Sequence__init(&msg->response, 0)) {
    hellocm_msgs__srv__Init_Event__fini(msg);
    return false;
  }
  return true;
}

void
hellocm_msgs__srv__Init_Event__fini(hellocm_msgs__srv__Init_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  hellocm_msgs__srv__Init_Request__Sequence__fini(&msg->request);
  // response
  hellocm_msgs__srv__Init_Response__Sequence__fini(&msg->response);
}

bool
hellocm_msgs__srv__Init_Event__are_equal(const hellocm_msgs__srv__Init_Event * lhs, const hellocm_msgs__srv__Init_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!hellocm_msgs__srv__Init_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!hellocm_msgs__srv__Init_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
hellocm_msgs__srv__Init_Event__copy(
  const hellocm_msgs__srv__Init_Event * input,
  hellocm_msgs__srv__Init_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!hellocm_msgs__srv__Init_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!hellocm_msgs__srv__Init_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

hellocm_msgs__srv__Init_Event *
hellocm_msgs__srv__Init_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Event * msg = (hellocm_msgs__srv__Init_Event *)allocator.allocate(sizeof(hellocm_msgs__srv__Init_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hellocm_msgs__srv__Init_Event));
  bool success = hellocm_msgs__srv__Init_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hellocm_msgs__srv__Init_Event__destroy(hellocm_msgs__srv__Init_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hellocm_msgs__srv__Init_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hellocm_msgs__srv__Init_Event__Sequence__init(hellocm_msgs__srv__Init_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Event * data = NULL;

  if (size) {
    data = (hellocm_msgs__srv__Init_Event *)allocator.zero_allocate(size, sizeof(hellocm_msgs__srv__Init_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hellocm_msgs__srv__Init_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hellocm_msgs__srv__Init_Event__fini(&data[i - 1]);
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
hellocm_msgs__srv__Init_Event__Sequence__fini(hellocm_msgs__srv__Init_Event__Sequence * array)
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
      hellocm_msgs__srv__Init_Event__fini(&array->data[i]);
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

hellocm_msgs__srv__Init_Event__Sequence *
hellocm_msgs__srv__Init_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hellocm_msgs__srv__Init_Event__Sequence * array = (hellocm_msgs__srv__Init_Event__Sequence *)allocator.allocate(sizeof(hellocm_msgs__srv__Init_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hellocm_msgs__srv__Init_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hellocm_msgs__srv__Init_Event__Sequence__destroy(hellocm_msgs__srv__Init_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hellocm_msgs__srv__Init_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hellocm_msgs__srv__Init_Event__Sequence__are_equal(const hellocm_msgs__srv__Init_Event__Sequence * lhs, const hellocm_msgs__srv__Init_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hellocm_msgs__srv__Init_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hellocm_msgs__srv__Init_Event__Sequence__copy(
  const hellocm_msgs__srv__Init_Event__Sequence * input,
  hellocm_msgs__srv__Init_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hellocm_msgs__srv__Init_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hellocm_msgs__srv__Init_Event * data =
      (hellocm_msgs__srv__Init_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hellocm_msgs__srv__Init_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hellocm_msgs__srv__Init_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hellocm_msgs__srv__Init_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
