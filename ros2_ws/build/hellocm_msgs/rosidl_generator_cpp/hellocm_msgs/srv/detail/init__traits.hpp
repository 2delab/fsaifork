// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hellocm_msgs/srv/init.hpp"


#ifndef HELLOCM_MSGS__SRV__DETAIL__INIT__TRAITS_HPP_
#define HELLOCM_MSGS__SRV__DETAIL__INIT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hellocm_msgs/srv/detail/init__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hellocm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Init_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Init_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Init_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hellocm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hellocm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hellocm_msgs::srv::Init_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hellocm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hellocm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hellocm_msgs::srv::Init_Request & msg)
{
  return hellocm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hellocm_msgs::srv::Init_Request>()
{
  return "hellocm_msgs::srv::Init_Request";
}

template<>
inline const char * name<hellocm_msgs::srv::Init_Request>()
{
  return "hellocm_msgs/srv/Init_Request";
}

template<>
struct has_fixed_size<hellocm_msgs::srv::Init_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hellocm_msgs::srv::Init_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hellocm_msgs::srv::Init_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hellocm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Init_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: cycletime
  {
    out << "cycletime: ";
    rosidl_generator_traits::value_to_yaml(msg.cycletime, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Init_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: cycletime
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cycletime: ";
    rosidl_generator_traits::value_to_yaml(msg.cycletime, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Init_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hellocm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hellocm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hellocm_msgs::srv::Init_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hellocm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hellocm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hellocm_msgs::srv::Init_Response & msg)
{
  return hellocm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hellocm_msgs::srv::Init_Response>()
{
  return "hellocm_msgs::srv::Init_Response";
}

template<>
inline const char * name<hellocm_msgs::srv::Init_Response>()
{
  return "hellocm_msgs/srv/Init_Response";
}

template<>
struct has_fixed_size<hellocm_msgs::srv::Init_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hellocm_msgs::srv::Init_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hellocm_msgs::srv::Init_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace hellocm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Init_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Init_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Init_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace hellocm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use hellocm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hellocm_msgs::srv::Init_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  hellocm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hellocm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const hellocm_msgs::srv::Init_Event & msg)
{
  return hellocm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<hellocm_msgs::srv::Init_Event>()
{
  return "hellocm_msgs::srv::Init_Event";
}

template<>
inline const char * name<hellocm_msgs::srv::Init_Event>()
{
  return "hellocm_msgs/srv/Init_Event";
}

template<>
struct has_fixed_size<hellocm_msgs::srv::Init_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hellocm_msgs::srv::Init_Event>
  : std::integral_constant<bool, has_bounded_size<hellocm_msgs::srv::Init_Request>::value && has_bounded_size<hellocm_msgs::srv::Init_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<hellocm_msgs::srv::Init_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hellocm_msgs::srv::Init>()
{
  return "hellocm_msgs::srv::Init";
}

template<>
inline const char * name<hellocm_msgs::srv::Init>()
{
  return "hellocm_msgs/srv/Init";
}

template<>
struct has_fixed_size<hellocm_msgs::srv::Init>
  : std::integral_constant<
    bool,
    has_fixed_size<hellocm_msgs::srv::Init_Request>::value &&
    has_fixed_size<hellocm_msgs::srv::Init_Response>::value
  >
{
};

template<>
struct has_bounded_size<hellocm_msgs::srv::Init>
  : std::integral_constant<
    bool,
    has_bounded_size<hellocm_msgs::srv::Init_Request>::value &&
    has_bounded_size<hellocm_msgs::srv::Init_Response>::value
  >
{
};

template<>
struct is_service<hellocm_msgs::srv::Init>
  : std::true_type
{
};

template<>
struct is_service_request<hellocm_msgs::srv::Init_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hellocm_msgs::srv::Init_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HELLOCM_MSGS__SRV__DETAIL__INIT__TRAITS_HPP_
