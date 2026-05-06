// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

#include "hellocm_msgs/srv/detail/init__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
const rosidl_type_hash_t *
hellocm_msgs__srv__Init__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd8, 0x0e, 0x1c, 0x5b, 0xc8, 0x31, 0x84, 0x01,
      0xbb, 0x58, 0x49, 0x2d, 0x85, 0xf5, 0xf6, 0x6d,
      0x36, 0xb0, 0x13, 0x3e, 0x28, 0xdd, 0xec, 0x20,
      0xe1, 0x18, 0xca, 0x05, 0xa3, 0x77, 0x4e, 0xac,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
const rosidl_type_hash_t *
hellocm_msgs__srv__Init_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x13, 0x02, 0xa3, 0x01, 0x35, 0xd5, 0x8c, 0x3a,
      0x71, 0x99, 0x64, 0x1f, 0x39, 0x84, 0x11, 0xdb,
      0x7c, 0x4e, 0x9b, 0x5d, 0x67, 0xc3, 0x2b, 0x79,
      0x4a, 0xcf, 0x31, 0xa6, 0x5a, 0x03, 0x94, 0x73,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
const rosidl_type_hash_t *
hellocm_msgs__srv__Init_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x11, 0xac, 0xd9, 0x57, 0xb5, 0x4b, 0xbe, 0x07,
      0xea, 0xe2, 0x3c, 0x0e, 0xf2, 0x36, 0x13, 0x07,
      0xcd, 0x54, 0xfe, 0xd8, 0x0b, 0x59, 0x43, 0xc0,
      0x12, 0x8b, 0x13, 0xee, 0xe1, 0xd8, 0xc8, 0xb3,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_hellocm_msgs
const rosidl_type_hash_t *
hellocm_msgs__srv__Init_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0x7b, 0x33, 0x45, 0xec, 0xb3, 0xfa, 0xaf,
      0xa3, 0xc7, 0x19, 0xdb, 0x8c, 0x56, 0xa2, 0xe3,
      0x48, 0x38, 0xdb, 0x6c, 0xd1, 0x0c, 0x3b, 0x47,
      0x4d, 0x11, 0xe5, 0x6a, 0x7d, 0xc6, 0xb1, 0x7e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char hellocm_msgs__srv__Init__TYPE_NAME[] = "hellocm_msgs/srv/Init";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char hellocm_msgs__srv__Init_Event__TYPE_NAME[] = "hellocm_msgs/srv/Init_Event";
static char hellocm_msgs__srv__Init_Request__TYPE_NAME[] = "hellocm_msgs/srv/Init_Request";
static char hellocm_msgs__srv__Init_Response__TYPE_NAME[] = "hellocm_msgs/srv/Init_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char hellocm_msgs__srv__Init__FIELD_NAME__request_message[] = "request_message";
static char hellocm_msgs__srv__Init__FIELD_NAME__response_message[] = "response_message";
static char hellocm_msgs__srv__Init__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field hellocm_msgs__srv__Init__FIELDS[] = {
  {
    {hellocm_msgs__srv__Init__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {hellocm_msgs__srv__Init_Request__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {hellocm_msgs__srv__Init_Response__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {hellocm_msgs__srv__Init_Event__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hellocm_msgs__srv__Init__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Event__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Request__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Response__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hellocm_msgs__srv__Init__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hellocm_msgs__srv__Init__TYPE_NAME, 21, 21},
      {hellocm_msgs__srv__Init__FIELDS, 3, 3},
    },
    {hellocm_msgs__srv__Init__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = hellocm_msgs__srv__Init_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = hellocm_msgs__srv__Init_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = hellocm_msgs__srv__Init_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char hellocm_msgs__srv__Init_Request__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field hellocm_msgs__srv__Init_Request__FIELDS[] = {
  {
    {hellocm_msgs__srv__Init_Request__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hellocm_msgs__srv__Init_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hellocm_msgs__srv__Init_Request__TYPE_NAME, 29, 29},
      {hellocm_msgs__srv__Init_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char hellocm_msgs__srv__Init_Response__FIELD_NAME__success[] = "success";
static char hellocm_msgs__srv__Init_Response__FIELD_NAME__cycletime[] = "cycletime";
static char hellocm_msgs__srv__Init_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field hellocm_msgs__srv__Init_Response__FIELDS[] = {
  {
    {hellocm_msgs__srv__Init_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Response__FIELD_NAME__cycletime, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hellocm_msgs__srv__Init_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hellocm_msgs__srv__Init_Response__TYPE_NAME, 30, 30},
      {hellocm_msgs__srv__Init_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char hellocm_msgs__srv__Init_Event__FIELD_NAME__info[] = "info";
static char hellocm_msgs__srv__Init_Event__FIELD_NAME__request[] = "request";
static char hellocm_msgs__srv__Init_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field hellocm_msgs__srv__Init_Event__FIELDS[] = {
  {
    {hellocm_msgs__srv__Init_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {hellocm_msgs__srv__Init_Request__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {hellocm_msgs__srv__Init_Response__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription hellocm_msgs__srv__Init_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Request__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {hellocm_msgs__srv__Init_Response__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
hellocm_msgs__srv__Init_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {hellocm_msgs__srv__Init_Event__TYPE_NAME, 27, 27},
      {hellocm_msgs__srv__Init_Event__FIELDS, 3, 3},
    },
    {hellocm_msgs__srv__Init_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = hellocm_msgs__srv__Init_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = hellocm_msgs__srv__Init_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# informational, e.g. name of triggering node\n"
  "string message\n"
  "\n"
  "---\n"
  "\n"
  "# indicate successful run of triggered service\n"
  "bool success\n"
  "\n"
  "# default cycle time in ms\n"
  "int32 cycletime\n"
  "\n"
  "# informational, e.g. for error messages\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
hellocm_msgs__srv__Init__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hellocm_msgs__srv__Init__TYPE_NAME, 21, 21},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 228, 228},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
hellocm_msgs__srv__Init_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hellocm_msgs__srv__Init_Request__TYPE_NAME, 29, 29},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
hellocm_msgs__srv__Init_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hellocm_msgs__srv__Init_Response__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
hellocm_msgs__srv__Init_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {hellocm_msgs__srv__Init_Event__TYPE_NAME, 27, 27},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hellocm_msgs__srv__Init__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hellocm_msgs__srv__Init__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *hellocm_msgs__srv__Init_Event__get_individual_type_description_source(NULL);
    sources[3] = *hellocm_msgs__srv__Init_Request__get_individual_type_description_source(NULL);
    sources[4] = *hellocm_msgs__srv__Init_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hellocm_msgs__srv__Init_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hellocm_msgs__srv__Init_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hellocm_msgs__srv__Init_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hellocm_msgs__srv__Init_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
hellocm_msgs__srv__Init_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *hellocm_msgs__srv__Init_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *hellocm_msgs__srv__Init_Request__get_individual_type_description_source(NULL);
    sources[3] = *hellocm_msgs__srv__Init_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
