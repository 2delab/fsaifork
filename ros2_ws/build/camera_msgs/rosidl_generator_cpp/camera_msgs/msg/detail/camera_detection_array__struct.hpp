// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from camera_msgs:msg/CameraDetectionArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "camera_msgs/msg/camera_detection_array.hpp"


#ifndef CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__STRUCT_HPP_
#define CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'detections'
#include "camera_msgs/msg/detail/camera_detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__camera_msgs__msg__CameraDetectionArray __attribute__((deprecated))
#else
# define DEPRECATED__camera_msgs__msg__CameraDetectionArray __declspec(deprecated)
#endif

namespace camera_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CameraDetectionArray_
{
  using Type = CameraDetectionArray_<ContainerAllocator>;

  explicit CameraDetectionArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit CameraDetectionArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _detections_type =
    std::vector<camera_msgs::msg::CameraDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<camera_msgs::msg::CameraDetection_<ContainerAllocator>>>;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__detections(
    const std::vector<camera_msgs::msg::CameraDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<camera_msgs::msg::CameraDetection_<ContainerAllocator>>> & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    camera_msgs::msg::CameraDetectionArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const camera_msgs::msg::CameraDetectionArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      camera_msgs::msg::CameraDetectionArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      camera_msgs::msg::CameraDetectionArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__camera_msgs__msg__CameraDetectionArray
    std::shared_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__camera_msgs__msg__CameraDetectionArray
    std::shared_ptr<camera_msgs::msg::CameraDetectionArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CameraDetectionArray_ & other) const
  {
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const CameraDetectionArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CameraDetectionArray_

// alias to use template instance with default allocator
using CameraDetectionArray =
  camera_msgs::msg::CameraDetectionArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace camera_msgs

#endif  // CAMERA_MSGS__MSG__DETAIL__CAMERA_DETECTION_ARRAY__STRUCT_HPP_
