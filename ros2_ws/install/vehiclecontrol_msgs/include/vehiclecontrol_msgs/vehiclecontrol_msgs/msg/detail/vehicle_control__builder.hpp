// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "vehiclecontrol_msgs/msg/vehicle_control.hpp"


#ifndef VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__BUILDER_HPP_
#define VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehiclecontrol_msgs/msg/detail/vehicle_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehiclecontrol_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleControl_steer_ang_acc
{
public:
  explicit Init_VehicleControl_steer_ang_acc(::vehiclecontrol_msgs::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  ::vehiclecontrol_msgs::msg::VehicleControl steer_ang_acc(::vehiclecontrol_msgs::msg::VehicleControl::_steer_ang_acc_type arg)
  {
    msg_.steer_ang_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

class Init_VehicleControl_steer_ang_vel
{
public:
  explicit Init_VehicleControl_steer_ang_vel(::vehiclecontrol_msgs::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  Init_VehicleControl_steer_ang_acc steer_ang_vel(::vehiclecontrol_msgs::msg::VehicleControl::_steer_ang_vel_type arg)
  {
    msg_.steer_ang_vel = std::move(arg);
    return Init_VehicleControl_steer_ang_acc(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

class Init_VehicleControl_steer_ang
{
public:
  explicit Init_VehicleControl_steer_ang(::vehiclecontrol_msgs::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  Init_VehicleControl_steer_ang_vel steer_ang(::vehiclecontrol_msgs::msg::VehicleControl::_steer_ang_type arg)
  {
    msg_.steer_ang = std::move(arg);
    return Init_VehicleControl_steer_ang_vel(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

class Init_VehicleControl_brake
{
public:
  explicit Init_VehicleControl_brake(::vehiclecontrol_msgs::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  Init_VehicleControl_steer_ang brake(::vehiclecontrol_msgs::msg::VehicleControl::_brake_type arg)
  {
    msg_.brake = std::move(arg);
    return Init_VehicleControl_steer_ang(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

class Init_VehicleControl_gas
{
public:
  explicit Init_VehicleControl_gas(::vehiclecontrol_msgs::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  Init_VehicleControl_brake gas(::vehiclecontrol_msgs::msg::VehicleControl::_gas_type arg)
  {
    msg_.gas = std::move(arg);
    return Init_VehicleControl_brake(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

class Init_VehicleControl_selector_ctrl
{
public:
  explicit Init_VehicleControl_selector_ctrl(::vehiclecontrol_msgs::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  Init_VehicleControl_gas selector_ctrl(::vehiclecontrol_msgs::msg::VehicleControl::_selector_ctrl_type arg)
  {
    msg_.selector_ctrl = std::move(arg);
    return Init_VehicleControl_gas(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

class Init_VehicleControl_use_vc
{
public:
  Init_VehicleControl_use_vc()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleControl_selector_ctrl use_vc(::vehiclecontrol_msgs::msg::VehicleControl::_use_vc_type arg)
  {
    msg_.use_vc = std::move(arg);
    return Init_VehicleControl_selector_ctrl(msg_);
  }

private:
  ::vehiclecontrol_msgs::msg::VehicleControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehiclecontrol_msgs::msg::VehicleControl>()
{
  return vehiclecontrol_msgs::msg::builder::Init_VehicleControl_use_vc();
}

}  // namespace vehiclecontrol_msgs

#endif  // VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__BUILDER_HPP_
