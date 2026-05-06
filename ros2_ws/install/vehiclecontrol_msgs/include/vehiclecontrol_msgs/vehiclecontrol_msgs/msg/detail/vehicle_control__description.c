// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice

#include "vehiclecontrol_msgs/msg/detail/vehicle_control__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_vehiclecontrol_msgs
const rosidl_type_hash_t *
vehiclecontrol_msgs__msg__VehicleControl__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9e, 0x35, 0x2d, 0xb5, 0xc3, 0x78, 0xee, 0x73,
      0x37, 0xff, 0x9f, 0x58, 0xf0, 0x8c, 0x35, 0x05,
      0xdc, 0xaa, 0x7f, 0xc7, 0x78, 0x07, 0xfa, 0x6c,
      0xd3, 0x1a, 0x26, 0x35, 0x12, 0xb9, 0x57, 0x55,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char vehiclecontrol_msgs__msg__VehicleControl__TYPE_NAME[] = "vehiclecontrol_msgs/msg/VehicleControl";

// Define type names, field names, and default values
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__use_vc[] = "use_vc";
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__selector_ctrl[] = "selector_ctrl";
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__gas[] = "gas";
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__brake[] = "brake";
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__steer_ang[] = "steer_ang";
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__steer_ang_vel[] = "steer_ang_vel";
static char vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__steer_ang_acc[] = "steer_ang_acc";

static rosidl_runtime_c__type_description__Field vehiclecontrol_msgs__msg__VehicleControl__FIELDS[] = {
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__use_vc, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__selector_ctrl, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__gas, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__brake, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__steer_ang, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__steer_ang_vel, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {vehiclecontrol_msgs__msg__VehicleControl__FIELD_NAME__steer_ang_acc, 13, 13},
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
vehiclecontrol_msgs__msg__VehicleControl__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {vehiclecontrol_msgs__msg__VehicleControl__TYPE_NAME, 38, 38},
      {vehiclecontrol_msgs__msg__VehicleControl__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#---------- ROS Message to map external signals to CarMaker Vehicle Control Quantities ---------- \n"
  "#*** Most of VC Interface outlined here...uncomment relevant quantities and assign in CMNode as demonstrated. ***\n"
  "\n"
  "#----- Flag to Use VC Input -----\n"
  "bool use_vc             # Set this flag to 1 in order to start writing to CarMaker VC quantities in this message.\n"
  "                        #   --> Used so that zeros are not sent over topic when no node is publishing to steer, brake, gas, etc.\n"
  "                        #   --> Allows driver or DiL to drive the vehicle via DM quantities and not be overwritten by VC if not needed.\n"
  "\n"
  "#----- Key / StartStop Button -----\n"
  "#int8 key                # Vehicle key position (integer):\n"
  "                        #   0: Key out\n"
  "                        #   1: Key in, power off\n"
  "                        #   2: Key in, power accessory\n"
  "                        #   3: Key in, power on\n"
  "                        #   4: Key in, starter active\n"
  "\n"
  "#bool sst                # Powertrain start-stop button (boolean): \n"
  "                        #   0=off\n"
  "                        #   1=on\n"
  "\n"
  "#----- Transmission -----\n"
  "int8 selector_ctrl      # PRNDL Position\n"
  "                        #   -9 = Park\n"
  "                        #   -1 = Reverse\n"
  "                        #    0 = Neutral\n"
  "                        #    1 = Drive\n"
  "                        #    2 = Manual gear selection (requires Manumatic transmission in CM model)\n"
  "\n"
  "#int8 gear               # Gear number for manual transmission...uncomment for use with manual transmission model.\n"
  "\n"
  "#----- Pedals -----\n"
  "float64 gas             # Gas pedal position [0 - 1]\n"
  "float64 brake           # Brake pedal position [0 - 1]\n"
  "#float64 clutch         # Clutch pedal position [0 - 1]...uncomment for use with manual transmission model.\n"
  "\n"
  "#----- Steering -----\n"
  "float64 steer_ang       # Steer angle [rad]\n"
  "float64 steer_ang_vel   # Steer angle velocity [rad/s]\n"
  "float64 steer_ang_acc   # Steer angle acceleration [rad/s^2]\n"
  "#float64 steer_trq      # Steering torque at steering wheel [N*m]...uncomment for use with GenTorque steering model (steer by torque).\n"
  "\n"
  "#----- Lights -----\n"
  "#bool brakelight         # Brake light on (boolean)\n"
  "#bool daytimelights      # Daytime running light on (boolean)\n"
  "#bool foglights_left     # Front fog left/right light on (boolean)\n"
  "#bool foglights_right\n"
  "#bool foglights_rear     # Rear fog light on (boolean)\n"
  "#bool highbeams          # High beam/full headlight on (boolean)\n"
  "#int8 indicator_left     # Indicator left/right (integer):\n"
  "#int8 indicator_right    #   0=Off; 1=Indicator on, light off; 2=Indicator on, light on\n"
  "#bool lowbeams           # Low beam/dipped headlight on (boolean)\n"
  "#bool parklight_left     # Parking left/right light on (boolean)\n"
  "#bool parklight_right    \n"
  "#bool reverselights      # Reversing light on (boolean)";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
vehiclecontrol_msgs__msg__VehicleControl__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {vehiclecontrol_msgs__msg__VehicleControl__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 2807, 2807},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
vehiclecontrol_msgs__msg__VehicleControl__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *vehiclecontrol_msgs__msg__VehicleControl__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
