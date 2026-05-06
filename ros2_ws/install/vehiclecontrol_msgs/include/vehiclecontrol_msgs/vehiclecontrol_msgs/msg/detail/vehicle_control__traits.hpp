// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "vehiclecontrol_msgs/msg/vehicle_control.hpp"


#ifndef VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__TRAITS_HPP_
#define VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehiclecontrol_msgs/msg/detail/vehicle_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vehiclecontrol_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: use_vc
  {
    out << "use_vc: ";
    rosidl_generator_traits::value_to_yaml(msg.use_vc, out);
    out << ", ";
  }

  // member: selector_ctrl
  {
    out << "selector_ctrl: ";
    rosidl_generator_traits::value_to_yaml(msg.selector_ctrl, out);
    out << ", ";
  }

  // member: gas
  {
    out << "gas: ";
    rosidl_generator_traits::value_to_yaml(msg.gas, out);
    out << ", ";
  }

  // member: brake
  {
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
    out << ", ";
  }

  // member: steer_ang
  {
    out << "steer_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_ang, out);
    out << ", ";
  }

  // member: steer_ang_vel
  {
    out << "steer_ang_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_ang_vel, out);
    out << ", ";
  }

  // member: steer_ang_acc
  {
    out << "steer_ang_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_ang_acc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: use_vc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_vc: ";
    rosidl_generator_traits::value_to_yaml(msg.use_vc, out);
    out << "\n";
  }

  // member: selector_ctrl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "selector_ctrl: ";
    rosidl_generator_traits::value_to_yaml(msg.selector_ctrl, out);
    out << "\n";
  }

  // member: gas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gas: ";
    rosidl_generator_traits::value_to_yaml(msg.gas, out);
    out << "\n";
  }

  // member: brake
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
    out << "\n";
  }

  // member: steer_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_ang, out);
    out << "\n";
  }

  // member: steer_ang_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_ang_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_ang_vel, out);
    out << "\n";
  }

  // member: steer_ang_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_ang_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_ang_acc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleControl & msg, bool use_flow_style = false)
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

}  // namespace vehiclecontrol_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vehiclecontrol_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vehiclecontrol_msgs::msg::VehicleControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehiclecontrol_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehiclecontrol_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehiclecontrol_msgs::msg::VehicleControl & msg)
{
  return vehiclecontrol_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehiclecontrol_msgs::msg::VehicleControl>()
{
  return "vehiclecontrol_msgs::msg::VehicleControl";
}

template<>
inline const char * name<vehiclecontrol_msgs::msg::VehicleControl>()
{
  return "vehiclecontrol_msgs/msg/VehicleControl";
}

template<>
struct has_fixed_size<vehiclecontrol_msgs::msg::VehicleControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vehiclecontrol_msgs::msg::VehicleControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vehiclecontrol_msgs::msg::VehicleControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__TRAITS_HPP_
