// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection_array.hpp"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__BUILDER_HPP_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "camera_msgs/msg/detail/camera_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace camera_msgs
{

namespace msg
{

namespace builder
{

class Init_CameraDetectionArray_detections
{
public:
  Init_CameraDetectionArray_detections()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::camera_msgs::msg::CameraDetectionArray detections(::camera_msgs::msg::CameraDetectionArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::camera_msgs::msg::CameraDetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_msgs::msg::CameraDetectionArray>()
{
  return camera_msgs::msg::builder::Init_CameraDetectionArray_detections();
}

}  // namespace camera_msgs

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__BUILDER_HPP_
