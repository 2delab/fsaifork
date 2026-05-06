// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection.hpp"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__STRUCT_HPP_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__camera_msgs__msg__CameraDetection __attribute__((deprecated))
#else
# define DEPRECATED__camera_msgs__msg__CameraDetection __declspec(deprecated)
#endif

namespace camera_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CameraDetection_
{
  using Type = CameraDetection_<ContainerAllocator>;

  explicit CameraDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->objid = 0l;
      this->objecttype = 0;
      this->nvispixels = 0ll;
      this->confidence = 0.0;
      this->mbr_bl_x = 0.0;
      this->mbr_bl_y = 0.0;
      this->mbr_bl_z = 0.0;
      this->mbr_tr_x = 0.0;
      this->mbr_tr_y = 0.0;
      this->mbr_tr_z = 0.0;
      this->facing = 0;
      this->lightstate = 0;
      this->signmain_val0 = 0.0;
      this->signmain_val1 = 0.0;
      this->signsuppl1_val0 = 0.0;
      this->signsuppl1_val1 = 0.0;
      this->signsuppl2_val0 = 0.0;
      this->signsuppl2_val1 = 0.0;
    }
  }

  explicit CameraDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->objid = 0l;
      this->objecttype = 0;
      this->nvispixels = 0ll;
      this->confidence = 0.0;
      this->mbr_bl_x = 0.0;
      this->mbr_bl_y = 0.0;
      this->mbr_bl_z = 0.0;
      this->mbr_tr_x = 0.0;
      this->mbr_tr_y = 0.0;
      this->mbr_tr_z = 0.0;
      this->facing = 0;
      this->lightstate = 0;
      this->signmain_val0 = 0.0;
      this->signmain_val1 = 0.0;
      this->signsuppl1_val0 = 0.0;
      this->signsuppl1_val1 = 0.0;
      this->signsuppl2_val0 = 0.0;
      this->signsuppl2_val1 = 0.0;
    }
  }

  // field types and members
  using _objid_type =
    int32_t;
  _objid_type objid;
  using _objecttype_type =
    int8_t;
  _objecttype_type objecttype;
  using _nvispixels_type =
    int64_t;
  _nvispixels_type nvispixels;
  using _confidence_type =
    double;
  _confidence_type confidence;
  using _mbr_bl_x_type =
    double;
  _mbr_bl_x_type mbr_bl_x;
  using _mbr_bl_y_type =
    double;
  _mbr_bl_y_type mbr_bl_y;
  using _mbr_bl_z_type =
    double;
  _mbr_bl_z_type mbr_bl_z;
  using _mbr_tr_x_type =
    double;
  _mbr_tr_x_type mbr_tr_x;
  using _mbr_tr_y_type =
    double;
  _mbr_tr_y_type mbr_tr_y;
  using _mbr_tr_z_type =
    double;
  _mbr_tr_z_type mbr_tr_z;
  using _facing_type =
    int8_t;
  _facing_type facing;
  using _lightstate_type =
    int8_t;
  _lightstate_type lightstate;
  using _signmain_val0_type =
    double;
  _signmain_val0_type signmain_val0;
  using _signmain_val1_type =
    double;
  _signmain_val1_type signmain_val1;
  using _signsuppl1_val0_type =
    double;
  _signsuppl1_val0_type signsuppl1_val0;
  using _signsuppl1_val1_type =
    double;
  _signsuppl1_val1_type signsuppl1_val1;
  using _signsuppl2_val0_type =
    double;
  _signsuppl2_val0_type signsuppl2_val0;
  using _signsuppl2_val1_type =
    double;
  _signsuppl2_val1_type signsuppl2_val1;

  // setters for named parameter idiom
  Type & set__objid(
    const int32_t & _arg)
  {
    this->objid = _arg;
    return *this;
  }
  Type & set__objecttype(
    const int8_t & _arg)
  {
    this->objecttype = _arg;
    return *this;
  }
  Type & set__nvispixels(
    const int64_t & _arg)
  {
    this->nvispixels = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__mbr_bl_x(
    const double & _arg)
  {
    this->mbr_bl_x = _arg;
    return *this;
  }
  Type & set__mbr_bl_y(
    const double & _arg)
  {
    this->mbr_bl_y = _arg;
    return *this;
  }
  Type & set__mbr_bl_z(
    const double & _arg)
  {
    this->mbr_bl_z = _arg;
    return *this;
  }
  Type & set__mbr_tr_x(
    const double & _arg)
  {
    this->mbr_tr_x = _arg;
    return *this;
  }
  Type & set__mbr_tr_y(
    const double & _arg)
  {
    this->mbr_tr_y = _arg;
    return *this;
  }
  Type & set__mbr_tr_z(
    const double & _arg)
  {
    this->mbr_tr_z = _arg;
    return *this;
  }
  Type & set__facing(
    const int8_t & _arg)
  {
    this->facing = _arg;
    return *this;
  }
  Type & set__lightstate(
    const int8_t & _arg)
  {
    this->lightstate = _arg;
    return *this;
  }
  Type & set__signmain_val0(
    const double & _arg)
  {
    this->signmain_val0 = _arg;
    return *this;
  }
  Type & set__signmain_val1(
    const double & _arg)
  {
    this->signmain_val1 = _arg;
    return *this;
  }
  Type & set__signsuppl1_val0(
    const double & _arg)
  {
    this->signsuppl1_val0 = _arg;
    return *this;
  }
  Type & set__signsuppl1_val1(
    const double & _arg)
  {
    this->signsuppl1_val1 = _arg;
    return *this;
  }
  Type & set__signsuppl2_val0(
    const double & _arg)
  {
    this->signsuppl2_val0 = _arg;
    return *this;
  }
  Type & set__signsuppl2_val1(
    const double & _arg)
  {
    this->signsuppl2_val1 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    camera_msgs::msg::CameraDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const camera_msgs::msg::CameraDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      camera_msgs::msg::CameraDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      camera_msgs::msg::CameraDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__camera_msgs__msg__CameraDetection
    std::shared_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__camera_msgs__msg__CameraDetection
    std::shared_ptr<camera_msgs::msg::CameraDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CameraDetection_ & other) const
  {
    if (this->objid != other.objid) {
      return false;
    }
    if (this->objecttype != other.objecttype) {
      return false;
    }
    if (this->nvispixels != other.nvispixels) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->mbr_bl_x != other.mbr_bl_x) {
      return false;
    }
    if (this->mbr_bl_y != other.mbr_bl_y) {
      return false;
    }
    if (this->mbr_bl_z != other.mbr_bl_z) {
      return false;
    }
    if (this->mbr_tr_x != other.mbr_tr_x) {
      return false;
    }
    if (this->mbr_tr_y != other.mbr_tr_y) {
      return false;
    }
    if (this->mbr_tr_z != other.mbr_tr_z) {
      return false;
    }
    if (this->facing != other.facing) {
      return false;
    }
    if (this->lightstate != other.lightstate) {
      return false;
    }
    if (this->signmain_val0 != other.signmain_val0) {
      return false;
    }
    if (this->signmain_val1 != other.signmain_val1) {
      return false;
    }
    if (this->signsuppl1_val0 != other.signsuppl1_val0) {
      return false;
    }
    if (this->signsuppl1_val1 != other.signsuppl1_val1) {
      return false;
    }
    if (this->signsuppl2_val0 != other.signsuppl2_val0) {
      return false;
    }
    if (this->signsuppl2_val1 != other.signsuppl2_val1) {
      return false;
    }
    return true;
  }
  bool operator!=(const CameraDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CameraDetection_

// alias to use template instance with default allocator
using CameraDetection =
  camera_msgs::msg::CameraDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace camera_msgs

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__STRUCT_HPP_
