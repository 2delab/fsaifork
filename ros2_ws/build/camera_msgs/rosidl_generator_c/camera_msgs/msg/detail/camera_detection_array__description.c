// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

#include "camera_msgs/msg/detail/camera_detection_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
const rosidl_type_hash_t *
camera_msgs__msg__CameraDetectionArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd0, 0x93, 0x8a, 0x96, 0xfd, 0xc3, 0x24, 0x56,
      0x16, 0xf0, 0xf5, 0xeb, 0x8b, 0x29, 0x3c, 0xda,
      0x98, 0xce, 0x2e, 0x18, 0xc1, 0x15, 0xd1, 0x2f,
      0x95, 0xbe, 0x51, 0x51, 0xbe, 0xbd, 0x16, 0xc9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "camera_msgs/msg/detail/camera_detection__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t camera_msgs__msg__CameraDetection__EXPECTED_HASH = {1, {
    0xaa, 0x66, 0xab, 0x4e, 0xfe, 0x6f, 0x8b, 0x70,
    0xef, 0xce, 0x7b, 0x86, 0x4a, 0xd5, 0xc0, 0xa9,
    0x50, 0x15, 0x3d, 0x17, 0x1a, 0xdd, 0xfc, 0xab,
    0xe2, 0x21, 0xc6, 0xec, 0xb6, 0x49, 0x8a, 0x08,
  }};
#endif

static char camera_msgs__msg__CameraDetectionArray__TYPE_NAME[] = "camera_msgs/msg/CameraDetectionArray";
static char camera_msgs__msg__CameraDetection__TYPE_NAME[] = "camera_msgs/msg/CameraDetection";

// Define type names, field names, and default values
static char camera_msgs__msg__CameraDetectionArray__FIELD_NAME__detections[] = "detections";

static rosidl_runtime_c__type_description__Field camera_msgs__msg__CameraDetectionArray__FIELDS[] = {
  {
    {camera_msgs__msg__CameraDetectionArray__FIELD_NAME__detections, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {camera_msgs__msg__CameraDetection__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription camera_msgs__msg__CameraDetectionArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {camera_msgs__msg__CameraDetection__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
camera_msgs__msg__CameraDetectionArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {camera_msgs__msg__CameraDetectionArray__TYPE_NAME, 36, 36},
      {camera_msgs__msg__CameraDetectionArray__FIELDS, 1, 1},
    },
    {camera_msgs__msg__CameraDetectionArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&camera_msgs__msg__CameraDetection__EXPECTED_HASH, camera_msgs__msg__CameraDetection__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = camera_msgs__msg__CameraDetection__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#~~~~~~~~~~ Custom ROS message for Camera HiFi Sensor Object List (array of detections) ~~~~~~~~~~\n"
  "camera_msgs/CameraDetection[] detections ";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
camera_msgs__msg__CameraDetectionArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {camera_msgs__msg__CameraDetectionArray__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 140, 140},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
camera_msgs__msg__CameraDetectionArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *camera_msgs__msg__CameraDetectionArray__get_individual_type_description_source(NULL),
    sources[1] = *camera_msgs__msg__CameraDetection__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
