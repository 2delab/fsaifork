// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:msg/Ext2CM.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hellocm_msgs/msg/ext2_cm.hpp"


#ifndef HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__TRAITS_HPP_
#define HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hellocm_msgs/msg/detail/ext2_cm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace hellocm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Ext2CM & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    to_flow_style_yaml(msg.time, out);
    out << ", ";
  }

  // member: cycleno
  {
    out << "cycleno: ";
    rosidl_generator_traits::value_to_yaml(msg.cycleno, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Ext2CM & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time:\n";
    to_block_style_yaml(msg.time, out, indentation + 2);
  }

  // member: cycleno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cycleno: ";
    rosidl_generator_traits::value_to_yaml(msg.cycleno, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Ext2CM & msg, bool use_flow_style = false)
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

}  // namespace hellocm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hellocm_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hellocm_msgs::msg::Ext2CM & msg,
  std::ostream & out, size_t indentation = 0)
{
  hellocm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hellocm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const hellocm_msgs::msg::Ext2CM & msg)
{
  return hellocm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<hellocm_msgs::msg::Ext2CM>()
{
  return "hellocm_msgs::msg::Ext2CM";
}

template<>
inline const char * name<hellocm_msgs::msg::Ext2CM>()
{
  return "hellocm_msgs/msg/Ext2CM";
}

template<>
struct has_fixed_size<hellocm_msgs::msg::Ext2CM>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<hellocm_msgs::msg::Ext2CM>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<hellocm_msgs::msg::Ext2CM>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__MSG__DETAIL__EXT2_CM__TRAITS_HPP_
