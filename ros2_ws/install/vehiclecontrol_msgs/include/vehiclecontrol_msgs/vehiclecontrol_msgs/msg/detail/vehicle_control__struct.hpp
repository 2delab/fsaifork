// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehiclecontrol_msgs:msg/VehicleControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "vehiclecontrol_msgs/msg/vehicle_control.hpp"


#ifndef VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_HPP_
#define VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vehiclecontrol_msgs__msg__VehicleControl __attribute__((deprecated))
#else
# define DEPRECATED__vehiclecontrol_msgs__msg__VehicleControl __declspec(deprecated)
#endif

namespace vehiclecontrol_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleControl_
{
  using Type = VehicleControl_<ContainerAllocator>;

  explicit VehicleControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->use_vc = false;
      this->selector_ctrl = 0;
      this->gas = 0.0;
      this->brake = 0.0;
      this->steer_ang = 0.0;
      this->steer_ang_vel = 0.0;
      this->steer_ang_acc = 0.0;
    }
  }

  explicit VehicleControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->use_vc = false;
      this->selector_ctrl = 0;
      this->gas = 0.0;
      this->brake = 0.0;
      this->steer_ang = 0.0;
      this->steer_ang_vel = 0.0;
      this->steer_ang_acc = 0.0;
    }
  }

  // field types and members
  using _use_vc_type =
    bool;
  _use_vc_type use_vc;
  using _selector_ctrl_type =
    int8_t;
  _selector_ctrl_type selector_ctrl;
  using _gas_type =
    double;
  _gas_type gas;
  using _brake_type =
    double;
  _brake_type brake;
  using _steer_ang_type =
    double;
  _steer_ang_type steer_ang;
  using _steer_ang_vel_type =
    double;
  _steer_ang_vel_type steer_ang_vel;
  using _steer_ang_acc_type =
    double;
  _steer_ang_acc_type steer_ang_acc;

  // setters for named parameter idiom
  Type & set__use_vc(
    const bool & _arg)
  {
    this->use_vc = _arg;
    return *this;
  }
  Type & set__selector_ctrl(
    const int8_t & _arg)
  {
    this->selector_ctrl = _arg;
    return *this;
  }
  Type & set__gas(
    const double & _arg)
  {
    this->gas = _arg;
    return *this;
  }
  Type & set__brake(
    const double & _arg)
  {
    this->brake = _arg;
    return *this;
  }
  Type & set__steer_ang(
    const double & _arg)
  {
    this->steer_ang = _arg;
    return *this;
  }
  Type & set__steer_ang_vel(
    const double & _arg)
  {
    this->steer_ang_vel = _arg;
    return *this;
  }
  Type & set__steer_ang_acc(
    const double & _arg)
  {
    this->steer_ang_acc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehiclecontrol_msgs__msg__VehicleControl
    std::shared_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehiclecontrol_msgs__msg__VehicleControl
    std::shared_ptr<vehiclecontrol_msgs::msg::VehicleControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleControl_ & other) const
  {
    if (this->use_vc != other.use_vc) {
      return false;
    }
    if (this->selector_ctrl != other.selector_ctrl) {
      return false;
    }
    if (this->gas != other.gas) {
      return false;
    }
    if (this->brake != other.brake) {
      return false;
    }
    if (this->steer_ang != other.steer_ang) {
      return false;
    }
    if (this->steer_ang_vel != other.steer_ang_vel) {
      return false;
    }
    if (this->steer_ang_acc != other.steer_ang_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleControl_

// alias to use template instance with default allocator
using VehicleControl =
  vehiclecontrol_msgs::msg::VehicleControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehiclecontrol_msgs

#endif  // VEHICLECONTROL_MSGS__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_HPP_
