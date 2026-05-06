// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection.hpp"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__BUILDER_HPP_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "camera_msgs/msg/detail/camera_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace camera_msgs
{

namespace msg
{

namespace builder
{

class Init_CameraDetection_signsuppl2_val1
{
public:
  explicit Init_CameraDetection_signsuppl2_val1(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  ::camera_msgs::msg::CameraDetection signsuppl2_val1(::camera_msgs::msg::CameraDetection::_signsuppl2_val1_type arg)
  {
    msg_.signsuppl2_val1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_signsuppl2_val0
{
public:
  explicit Init_CameraDetection_signsuppl2_val0(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_signsuppl2_val1 signsuppl2_val0(::camera_msgs::msg::CameraDetection::_signsuppl2_val0_type arg)
  {
    msg_.signsuppl2_val0 = std::move(arg);
    return Init_CameraDetection_signsuppl2_val1(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_signsuppl1_val1
{
public:
  explicit Init_CameraDetection_signsuppl1_val1(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_signsuppl2_val0 signsuppl1_val1(::camera_msgs::msg::CameraDetection::_signsuppl1_val1_type arg)
  {
    msg_.signsuppl1_val1 = std::move(arg);
    return Init_CameraDetection_signsuppl2_val0(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_signsuppl1_val0
{
public:
  explicit Init_CameraDetection_signsuppl1_val0(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_signsuppl1_val1 signsuppl1_val0(::camera_msgs::msg::CameraDetection::_signsuppl1_val0_type arg)
  {
    msg_.signsuppl1_val0 = std::move(arg);
    return Init_CameraDetection_signsuppl1_val1(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_signmain_val1
{
public:
  explicit Init_CameraDetection_signmain_val1(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_signsuppl1_val0 signmain_val1(::camera_msgs::msg::CameraDetection::_signmain_val1_type arg)
  {
    msg_.signmain_val1 = std::move(arg);
    return Init_CameraDetection_signsuppl1_val0(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_signmain_val0
{
public:
  explicit Init_CameraDetection_signmain_val0(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_signmain_val1 signmain_val0(::camera_msgs::msg::CameraDetection::_signmain_val0_type arg)
  {
    msg_.signmain_val0 = std::move(arg);
    return Init_CameraDetection_signmain_val1(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_lightstate
{
public:
  explicit Init_CameraDetection_lightstate(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_signmain_val0 lightstate(::camera_msgs::msg::CameraDetection::_lightstate_type arg)
  {
    msg_.lightstate = std::move(arg);
    return Init_CameraDetection_signmain_val0(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_facing
{
public:
  explicit Init_CameraDetection_facing(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_lightstate facing(::camera_msgs::msg::CameraDetection::_facing_type arg)
  {
    msg_.facing = std::move(arg);
    return Init_CameraDetection_lightstate(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_mbr_tr_z
{
public:
  explicit Init_CameraDetection_mbr_tr_z(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_facing mbr_tr_z(::camera_msgs::msg::CameraDetection::_mbr_tr_z_type arg)
  {
    msg_.mbr_tr_z = std::move(arg);
    return Init_CameraDetection_facing(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_mbr_tr_y
{
public:
  explicit Init_CameraDetection_mbr_tr_y(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_mbr_tr_z mbr_tr_y(::camera_msgs::msg::CameraDetection::_mbr_tr_y_type arg)
  {
    msg_.mbr_tr_y = std::move(arg);
    return Init_CameraDetection_mbr_tr_z(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_mbr_tr_x
{
public:
  explicit Init_CameraDetection_mbr_tr_x(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_mbr_tr_y mbr_tr_x(::camera_msgs::msg::CameraDetection::_mbr_tr_x_type arg)
  {
    msg_.mbr_tr_x = std::move(arg);
    return Init_CameraDetection_mbr_tr_y(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_mbr_bl_z
{
public:
  explicit Init_CameraDetection_mbr_bl_z(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_mbr_tr_x mbr_bl_z(::camera_msgs::msg::CameraDetection::_mbr_bl_z_type arg)
  {
    msg_.mbr_bl_z = std::move(arg);
    return Init_CameraDetection_mbr_tr_x(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_mbr_bl_y
{
public:
  explicit Init_CameraDetection_mbr_bl_y(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_mbr_bl_z mbr_bl_y(::camera_msgs::msg::CameraDetection::_mbr_bl_y_type arg)
  {
    msg_.mbr_bl_y = std::move(arg);
    return Init_CameraDetection_mbr_bl_z(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_mbr_bl_x
{
public:
  explicit Init_CameraDetection_mbr_bl_x(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_mbr_bl_y mbr_bl_x(::camera_msgs::msg::CameraDetection::_mbr_bl_x_type arg)
  {
    msg_.mbr_bl_x = std::move(arg);
    return Init_CameraDetection_mbr_bl_y(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_confidence
{
public:
  explicit Init_CameraDetection_confidence(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_mbr_bl_x confidence(::camera_msgs::msg::CameraDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_CameraDetection_mbr_bl_x(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_nvispixels
{
public:
  explicit Init_CameraDetection_nvispixels(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_confidence nvispixels(::camera_msgs::msg::CameraDetection::_nvispixels_type arg)
  {
    msg_.nvispixels = std::move(arg);
    return Init_CameraDetection_confidence(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_objecttype
{
public:
  explicit Init_CameraDetection_objecttype(::camera_msgs::msg::CameraDetection & msg)
  : msg_(msg)
  {}
  Init_CameraDetection_nvispixels objecttype(::camera_msgs::msg::CameraDetection::_objecttype_type arg)
  {
    msg_.objecttype = std::move(arg);
    return Init_CameraDetection_nvispixels(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

class Init_CameraDetection_objid
{
public:
  Init_CameraDetection_objid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CameraDetection_objecttype objid(::camera_msgs::msg::CameraDetection::_objid_type arg)
  {
    msg_.objid = std::move(arg);
    return Init_CameraDetection_objecttype(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_msgs::msg::CameraDetection>()
{
  return camera_msgs::msg::builder::Init_CameraDetection_objid();
}

}  // namespace camera_msgs

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION__BUILDER_HPP_
