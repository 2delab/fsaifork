// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from camera_msgs:msg/CameraDetection.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "camera_msgs/msg/detail/camera_detection__struct.h"
#include "camera_msgs/msg/detail/camera_detection__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool camera_msgs__msg__camera_detection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("camera_msgs.msg._camera_detection.CameraDetection", full_classname_dest, 49) == 0);
  }
  camera_msgs__msg__CameraDetection * ros_message = _ros_message;
  {  // objid
    PyObject * field = PyObject_GetAttrString(_pymsg, "objid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->objid = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // objecttype
    PyObject * field = PyObject_GetAttrString(_pymsg, "objecttype");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->objecttype = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // nvispixels
    PyObject * field = PyObject_GetAttrString(_pymsg, "nvispixels");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nvispixels = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // confidence
    PyObject * field = PyObject_GetAttrString(_pymsg, "confidence");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->confidence = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mbr_bl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "mbr_bl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mbr_bl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mbr_bl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "mbr_bl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mbr_bl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mbr_bl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "mbr_bl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mbr_bl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mbr_tr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "mbr_tr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mbr_tr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mbr_tr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "mbr_tr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mbr_tr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mbr_tr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "mbr_tr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mbr_tr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // facing
    PyObject * field = PyObject_GetAttrString(_pymsg, "facing");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->facing = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // lightstate
    PyObject * field = PyObject_GetAttrString(_pymsg, "lightstate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lightstate = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // signmain_val0
    PyObject * field = PyObject_GetAttrString(_pymsg, "signmain_val0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->signmain_val0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // signmain_val1
    PyObject * field = PyObject_GetAttrString(_pymsg, "signmain_val1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->signmain_val1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // signsuppl1_val0
    PyObject * field = PyObject_GetAttrString(_pymsg, "signsuppl1_val0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->signsuppl1_val0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // signsuppl1_val1
    PyObject * field = PyObject_GetAttrString(_pymsg, "signsuppl1_val1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->signsuppl1_val1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // signsuppl2_val0
    PyObject * field = PyObject_GetAttrString(_pymsg, "signsuppl2_val0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->signsuppl2_val0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // signsuppl2_val1
    PyObject * field = PyObject_GetAttrString(_pymsg, "signsuppl2_val1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->signsuppl2_val1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * camera_msgs__msg__camera_detection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CameraDetection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("camera_msgs.msg._camera_detection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CameraDetection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  camera_msgs__msg__CameraDetection * ros_message = (camera_msgs__msg__CameraDetection *)raw_ros_message;
  {  // objid
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->objid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "objid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // objecttype
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->objecttype);
    {
      int rc = PyObject_SetAttrString(_pymessage, "objecttype", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nvispixels
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->nvispixels);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nvispixels", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // confidence
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->confidence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "confidence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mbr_bl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mbr_bl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mbr_bl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mbr_bl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mbr_bl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mbr_bl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mbr_bl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mbr_bl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mbr_bl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mbr_tr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mbr_tr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mbr_tr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mbr_tr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mbr_tr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mbr_tr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mbr_tr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mbr_tr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mbr_tr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // facing
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->facing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "facing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lightstate
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lightstate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lightstate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signmain_val0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->signmain_val0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signmain_val0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signmain_val1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->signmain_val1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signmain_val1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signsuppl1_val0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->signsuppl1_val0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signsuppl1_val0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signsuppl1_val1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->signsuppl1_val1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signsuppl1_val1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signsuppl2_val0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->signsuppl2_val0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signsuppl2_val0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signsuppl2_val1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->signsuppl2_val1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signsuppl2_val1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
