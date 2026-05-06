// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection.hpp"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__TRAITS_HPP_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "camera_msgs/msg/detail/camera_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CameraDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: objid
  {
    out << "objid: ";
    rosidl_generator_traits::value_to_yaml(msg.objid, out);
    out << ", ";
  }

  // member: objecttype
  {
    out << "objecttype: ";
    rosidl_generator_traits::value_to_yaml(msg.objecttype, out);
    out << ", ";
  }

  // member: nvispixels
  {
    out << "nvispixels: ";
    rosidl_generator_traits::value_to_yaml(msg.nvispixels, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: mbr_bl_x
  {
    out << "mbr_bl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_bl_x, out);
    out << ", ";
  }

  // member: mbr_bl_y
  {
    out << "mbr_bl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_bl_y, out);
    out << ", ";
  }

  // member: mbr_bl_z
  {
    out << "mbr_bl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_bl_z, out);
    out << ", ";
  }

  // member: mbr_tr_x
  {
    out << "mbr_tr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_tr_x, out);
    out << ", ";
  }

  // member: mbr_tr_y
  {
    out << "mbr_tr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_tr_y, out);
    out << ", ";
  }

  // member: mbr_tr_z
  {
    out << "mbr_tr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_tr_z, out);
    out << ", ";
  }

  // member: facing
  {
    out << "facing: ";
    rosidl_generator_traits::value_to_yaml(msg.facing, out);
    out << ", ";
  }

  // member: lightstate
  {
    out << "lightstate: ";
    rosidl_generator_traits::value_to_yaml(msg.lightstate, out);
    out << ", ";
  }

  // member: signmain_val0
  {
    out << "signmain_val0: ";
    rosidl_generator_traits::value_to_yaml(msg.signmain_val0, out);
    out << ", ";
  }

  // member: signmain_val1
  {
    out << "signmain_val1: ";
    rosidl_generator_traits::value_to_yaml(msg.signmain_val1, out);
    out << ", ";
  }

  // member: signsuppl1_val0
  {
    out << "signsuppl1_val0: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl1_val0, out);
    out << ", ";
  }

  // member: signsuppl1_val1
  {
    out << "signsuppl1_val1: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl1_val1, out);
    out << ", ";
  }

  // member: signsuppl2_val0
  {
    out << "signsuppl2_val0: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl2_val0, out);
    out << ", ";
  }

  // member: signsuppl2_val1
  {
    out << "signsuppl2_val1: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl2_val1, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CameraDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: objid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "objid: ";
    rosidl_generator_traits::value_to_yaml(msg.objid, out);
    out << "\n";
  }

  // member: objecttype
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "objecttype: ";
    rosidl_generator_traits::value_to_yaml(msg.objecttype, out);
    out << "\n";
  }

  // member: nvispixels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nvispixels: ";
    rosidl_generator_traits::value_to_yaml(msg.nvispixels, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: mbr_bl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mbr_bl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_bl_x, out);
    out << "\n";
  }

  // member: mbr_bl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mbr_bl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_bl_y, out);
    out << "\n";
  }

  // member: mbr_bl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mbr_bl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_bl_z, out);
    out << "\n";
  }

  // member: mbr_tr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mbr_tr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_tr_x, out);
    out << "\n";
  }

  // member: mbr_tr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mbr_tr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_tr_y, out);
    out << "\n";
  }

  // member: mbr_tr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mbr_tr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.mbr_tr_z, out);
    out << "\n";
  }

  // member: facing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "facing: ";
    rosidl_generator_traits::value_to_yaml(msg.facing, out);
    out << "\n";
  }

  // member: lightstate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lightstate: ";
    rosidl_generator_traits::value_to_yaml(msg.lightstate, out);
    out << "\n";
  }

  // member: signmain_val0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signmain_val0: ";
    rosidl_generator_traits::value_to_yaml(msg.signmain_val0, out);
    out << "\n";
  }

  // member: signmain_val1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signmain_val1: ";
    rosidl_generator_traits::value_to_yaml(msg.signmain_val1, out);
    out << "\n";
  }

  // member: signsuppl1_val0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signsuppl1_val0: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl1_val0, out);
    out << "\n";
  }

  // member: signsuppl1_val1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signsuppl1_val1: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl1_val1, out);
    out << "\n";
  }

  // member: signsuppl2_val0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signsuppl2_val0: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl2_val0, out);
    out << "\n";
  }

  // member: signsuppl2_val1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signsuppl2_val1: ";
    rosidl_generator_traits::value_to_yaml(msg.signsuppl2_val1, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CameraDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use camera_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const camera_msgs::msg::CameraDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const camera_msgs::msg::CameraDetection & msg)
{
  return camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<camera_msgs::msg::CameraDetection>()
{
  return "camera_msgs::msg::CameraDetection";
}

template<>
inline const char * name<camera_msgs::msg::CameraDetection>()
{
  return "camera_msgs/msg/CameraDetection";
}

template<>
struct has_fixed_size<camera_msgs::msg::CameraDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<camera_msgs::msg::CameraDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<camera_msgs::msg::CameraDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__TRAITS_HPP_
