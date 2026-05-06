// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hellocm_msgs:msg/CM2Ext.idl
// generated code does not contain a copyright notice

#include "hellocm_msgs/msg/detail/cm2_ext__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
const rosidl_type_hash_t *
hellocm_msgs__msg__CM2Ext__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9c, 0xc7, 0x2e, 0xc1, 0xb5, 0x35, 0x5c, 0xbe,
      0xbc, 0x3d, 0xaa, 0xd1, 0xe8, 0x12, 0xbf, 0x90,
      0x58, 0x80, 0xac, 0x3c, 0x1d, 0x96, 0xbb, 0xbb,
      0x79, 0x77, 0x8a, 0xad, 0x74, 0x84, 0x0e, 0x1e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char hellocm_msgs__msg__CM2Ext__TYPE_NAME[] = "hellocm_msgs/msg/CM2Ext";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char hellocm_msgs__msg__CM2Ext__FIELD_NAME__header[] = "header";
static char hellocm_msgs__msg__CM2Ext__FIELD_NAME__time[] = "time";
static char hellocm_msgs__msg__CM2Ext__FIELD_NAME__cycleno[] = "cycleno";
static char hellocm_msgs__msg__CM2Ext__FIELD_NAME__synthdelay[] = "synthdelay";

static rosidl_runtime_c__type_description__Field hellocm_msgs__msg__CM2Ext__FIELDS[] = {
  {
    {hellocm_msgs__msg__CM2Ext__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__msg__CM2Ext__FIELD_NAME__time, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__msg__CM2Ext__FIELD_NAME__cycleno, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__msg__CM2Ext__FIELD_NAME__synthdelay, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hellocm_msgs__msg__CM2Ext__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hellocm_msgs__msg__CM2Ext__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hellocm_msgs__msg__CM2Ext__TYPE_NAME, 23, 23},
      {hellocm_msgs__msg__CM2Ext__FIELDS, 4, 4},
    },
    {hellocm_msgs__msg__CM2Ext__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#\n"
  "# Message from CarMaker ROS Node to external ROS Node\n"
  "#\n"
  "\n"
  "# General ROS Header (optional)\n"
  "std_msgs/Header header\n"
  "\n"
  "# ROS time when message was sent (optional)\n"
  "builtin_interfaces/Time time\n"
  "\n"
  "# Cycle number since simulation start (optional)\n"
  "int64 cycleno\n"
  "\n"
  "# Synthetic delay to check synchronization (optional)\n"
  "float64 synthdelay";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hellocm_msgs__msg__CM2Ext__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hellocm_msgs__msg__CM2Ext__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 326, 326},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hellocm_msgs__msg__CM2Ext__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hellocm_msgs__msg__CM2Ext__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
