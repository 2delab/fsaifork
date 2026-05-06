// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hellocm_msgs:srv/Init.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "hellocm_msgs/srv/init.hpp"


#ifndef HELLOCM_MSGS__SRV__DETAIL__INIT__BUILDER_HPP_
#define HELLOCM_MSGS__SRV__DETAIL__INIT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hellocm_msgs/srv/detail/init__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hellocm_msgs
{

namespace srv
{

namespace builder
{

class Init_Init_Request_message
{
public:
  Init_Init_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hellocm_msgs::srv::Init_Request message(::hellocm_msgs::srv::Init_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::srv::Init_Request>()
{
  return hellocm_msgs::srv::builder::Init_Init_Request_message();
}

}  // namespace hellocm_msgs


namespace hellocm_msgs
{

namespace srv
{

namespace builder
{

class Init_Init_Response_message
{
public:
  explicit Init_Init_Response_message(::hellocm_msgs::srv::Init_Response & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::srv::Init_Response message(::hellocm_msgs::srv::Init_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Response msg_;
};

class Init_Init_Response_cycletime
{
public:
  explicit Init_Init_Response_cycletime(::hellocm_msgs::srv::Init_Response & msg)
  : msg_(msg)
  {}
  Init_Init_Response_message cycletime(::hellocm_msgs::srv::Init_Response::_cycletime_type arg)
  {
    msg_.cycletime = std::move(arg);
    return Init_Init_Response_message(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Response msg_;
};

class Init_Init_Response_success
{
public:
  Init_Init_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Init_Response_cycletime success(::hellocm_msgs::srv::Init_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Init_Response_cycletime(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::srv::Init_Response>()
{
  return hellocm_msgs::srv::builder::Init_Init_Response_success();
}

}  // namespace hellocm_msgs


namespace hellocm_msgs
{

namespace srv
{

namespace builder
{

class Init_Init_Event_response
{
public:
  explicit Init_Init_Event_response(::hellocm_msgs::srv::Init_Event & msg)
  : msg_(msg)
  {}
  ::hellocm_msgs::srv::Init_Event response(::hellocm_msgs::srv::Init_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Event msg_;
};

class Init_Init_Event_request
{
public:
  explicit Init_Init_Event_request(::hellocm_msgs::srv::Init_Event & msg)
  : msg_(msg)
  {}
  Init_Init_Event_response request(::hellocm_msgs::srv::Init_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Init_Event_response(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Event msg_;
};

class Init_Init_Event_info
{
public:
  Init_Init_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Init_Event_request info(::hellocm_msgs::srv::Init_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Init_Event_request(msg_);
  }

private:
  ::hellocm_msgs::srv::Init_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hellocm_msgs::srv::Init_Event>()
{
  return hellocm_msgs::srv::builder::Init_Init_Event_info();
}

}  // namespace hellocm_msgs

#endif  // HELLOCM_MSGS__SRV__DETAIL__INIT__BUILDER_HPP_
