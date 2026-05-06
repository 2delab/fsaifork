// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice

#include "camera_msgs/msg/detail/camera_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_camera_msgs
const rosidl_type_hash_t *
camera_msgs__msg__CameraDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaa, 0x66, 0xab, 0x4e, 0xfe, 0x6f, 0x8b, 0x70,
      0xef, 0xce, 0x7b, 0x86, 0x4a, 0xd5, 0xc0, 0xa9,
      0x50, 0x15, 0x3d, 0x17, 0x1a, 0xdd, 0xfc, 0xab,
      0xe2, 0x21, 0xc6, 0xec, 0xb6, 0x49, 0x8a, 0x08,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char camera_msgs__msg__CameraDetection__TYPE_NAME[] = "camera_msgs/msg/CameraDetection";

// Define type names, field names, and default values
static char camera_msgs__msg__CameraDetection__FIELD_NAME__objid[] = "objid";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__objecttype[] = "objecttype";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__nvispixels[] = "nvispixels";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__confidence[] = "confidence";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_bl_x[] = "mbr_bl_x";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_bl_y[] = "mbr_bl_y";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_bl_z[] = "mbr_bl_z";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_tr_x[] = "mbr_tr_x";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_tr_y[] = "mbr_tr_y";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_tr_z[] = "mbr_tr_z";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__facing[] = "facing";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__lightstate[] = "lightstate";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__signmain_val0[] = "signmain_val0";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__signmain_val1[] = "signmain_val1";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl1_val0[] = "signsuppl1_val0";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl1_val1[] = "signsuppl1_val1";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl2_val0[] = "signsuppl2_val0";
static char camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl2_val1[] = "signsuppl2_val1";

static rosidl_runtime_c__type_description__Field camera_msgs__msg__CameraDetection__FIELDS[] = {
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__objid, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__objecttype, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__nvispixels, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_bl_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_bl_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_bl_z, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_tr_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_tr_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__mbr_tr_z, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__facing, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__lightstate, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__signmain_val0, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__signmain_val1, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl1_val0, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl1_val1, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl2_val0, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {camera_msgs__msg__CameraDetection__FIELD_NAME__signsuppl2_val1, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
camera_msgs__msg__CameraDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {camera_msgs__msg__CameraDetection__TYPE_NAME, 31, 31},
      {camera_msgs__msg__CameraDetection__FIELDS, 18, 18},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#~~~~~~~~~~ Custom ROS message for HiFi Camera Sensor ~~~~~~~~~~\n"
  "\n"
  "#~~~~~ Quantities match UAQs for HiFi Camera Sensor in CM\n"
  "#~~~~~ See 'Reference Manual --> User Accessible Quantities --> Sensors --> Camera Sensor' for full descriptions.\n"
  "\n"
  "int32           objid                   # global ID to identify object (integer) \n"
  "\n"
  "int8            objecttype                    # camera object type (integer)\n"
  "                                        #   0 - Car\n"
  "                                        #   1 - Truck\n"
  "                                        #   2 - Bicycle\n"
  "                                        #   3 - Pedestrian\n"
  "                                        #   4 - Traffic sign\n"
  "                                        #   5 - Traffic light\n"
  "\n"
  "int64           nvispixels              # number of visible pixels (integer)\n"
  "\n"
  "float64         confidence              # indicates how much of the object is visible\n"
  "\n"
  "float64         mbr_bl_x                # minimum bounding rectangle - bottom left and top right points\n"
  "float64         mbr_bl_y                \n"
  "float64         mbr_bl_z                \n"
  "float64         mbr_tr_x                \n"
  "float64         mbr_tr_y                \n"
  "float64         mbr_tr_z                \n"
  "\n"
  "int8            facing                  # 0: not facing sensor, 1: facing sensor\n"
  "\n"
  "int8            lightstate              # Traffic light state/phase (integer):\n"
  "                                        #   0: All lights off\n"
  "                                        #   1: Green light on\n"
  "                                        #   2: Yellow light on\n"
  "                                        #   3: Red light on\n"
  "                                        #   4: Red-Yellow light on\n"
  "\n"
  "float64         signmain_val0           # User defined sign attribute values\n"
  "float64         signmain_val1           \n"
  "float64         signsuppl1_val0         \n"
  "float64         signsuppl1_val1         \n"
  "float64         signsuppl2_val0         \n"
  "float64         signsuppl2_val1        ";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
camera_msgs__msg__CameraDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {camera_msgs__msg__CameraDetection__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1975, 1975},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
camera_msgs__msg__CameraDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *camera_msgs__msg__CameraDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
