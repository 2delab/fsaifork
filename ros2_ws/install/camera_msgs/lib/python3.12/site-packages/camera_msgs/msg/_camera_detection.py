# generated from rosidl_generator_py/resource/_idl.py.em
# with input from camera_msgs:msg/CameraDetection.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CameraDetection(type):
    """Metaclass of message 'CameraDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('camera_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'camera_msgs.msg.CameraDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__camera_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__camera_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__camera_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__camera_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__camera_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CameraDetection(metaclass=Metaclass_CameraDetection):
    """Message class 'CameraDetection'."""

    __slots__ = [
        '_objid',
        '_objecttype',
        '_nvispixels',
        '_confidence',
        '_mbr_bl_x',
        '_mbr_bl_y',
        '_mbr_bl_z',
        '_mbr_tr_x',
        '_mbr_tr_y',
        '_mbr_tr_z',
        '_facing',
        '_lightstate',
        '_signmain_val0',
        '_signmain_val1',
        '_signsuppl1_val0',
        '_signsuppl1_val1',
        '_signsuppl2_val0',
        '_signsuppl2_val1',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'objid': 'int32',
        'objecttype': 'int8',
        'nvispixels': 'int64',
        'confidence': 'double',
        'mbr_bl_x': 'double',
        'mbr_bl_y': 'double',
        'mbr_bl_z': 'double',
        'mbr_tr_x': 'double',
        'mbr_tr_y': 'double',
        'mbr_tr_z': 'double',
        'facing': 'int8',
        'lightstate': 'int8',
        'signmain_val0': 'double',
        'signmain_val1': 'double',
        'signsuppl1_val0': 'double',
        'signsuppl1_val1': 'double',
        'signsuppl2_val0': 'double',
        'signsuppl2_val1': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.objid = kwargs.get('objid', int())
        self.objecttype = kwargs.get('objecttype', int())
        self.nvispixels = kwargs.get('nvispixels', int())
        self.confidence = kwargs.get('confidence', float())
        self.mbr_bl_x = kwargs.get('mbr_bl_x', float())
        self.mbr_bl_y = kwargs.get('mbr_bl_y', float())
        self.mbr_bl_z = kwargs.get('mbr_bl_z', float())
        self.mbr_tr_x = kwargs.get('mbr_tr_x', float())
        self.mbr_tr_y = kwargs.get('mbr_tr_y', float())
        self.mbr_tr_z = kwargs.get('mbr_tr_z', float())
        self.facing = kwargs.get('facing', int())
        self.lightstate = kwargs.get('lightstate', int())
        self.signmain_val0 = kwargs.get('signmain_val0', float())
        self.signmain_val1 = kwargs.get('signmain_val1', float())
        self.signsuppl1_val0 = kwargs.get('signsuppl1_val0', float())
        self.signsuppl1_val1 = kwargs.get('signsuppl1_val1', float())
        self.signsuppl2_val0 = kwargs.get('signsuppl2_val0', float())
        self.signsuppl2_val1 = kwargs.get('signsuppl2_val1', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.objid != other.objid:
            return False
        if self.objecttype != other.objecttype:
            return False
        if self.nvispixels != other.nvispixels:
            return False
        if self.confidence != other.confidence:
            return False
        if self.mbr_bl_x != other.mbr_bl_x:
            return False
        if self.mbr_bl_y != other.mbr_bl_y:
            return False
        if self.mbr_bl_z != other.mbr_bl_z:
            return False
        if self.mbr_tr_x != other.mbr_tr_x:
            return False
        if self.mbr_tr_y != other.mbr_tr_y:
            return False
        if self.mbr_tr_z != other.mbr_tr_z:
            return False
        if self.facing != other.facing:
            return False
        if self.lightstate != other.lightstate:
            return False
        if self.signmain_val0 != other.signmain_val0:
            return False
        if self.signmain_val1 != other.signmain_val1:
            return False
        if self.signsuppl1_val0 != other.signsuppl1_val0:
            return False
        if self.signsuppl1_val1 != other.signsuppl1_val1:
            return False
        if self.signsuppl2_val0 != other.signsuppl2_val0:
            return False
        if self.signsuppl2_val1 != other.signsuppl2_val1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def objid(self):
        """Message field 'objid'."""
        return self._objid

    @objid.setter
    def objid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'objid' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'objid' field must be an integer in [-2147483648, 2147483647]"
        self._objid = value

    @builtins.property
    def objecttype(self):
        """Message field 'objecttype'."""
        return self._objecttype

    @objecttype.setter
    def objecttype(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'objecttype' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'objecttype' field must be an integer in [-128, 127]"
        self._objecttype = value

    @builtins.property
    def nvispixels(self):
        """Message field 'nvispixels'."""
        return self._nvispixels

    @nvispixels.setter
    def nvispixels(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'nvispixels' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'nvispixels' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._nvispixels = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence = value

    @builtins.property
    def mbr_bl_x(self):
        """Message field 'mbr_bl_x'."""
        return self._mbr_bl_x

    @mbr_bl_x.setter
    def mbr_bl_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mbr_bl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mbr_bl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mbr_bl_x = value

    @builtins.property
    def mbr_bl_y(self):
        """Message field 'mbr_bl_y'."""
        return self._mbr_bl_y

    @mbr_bl_y.setter
    def mbr_bl_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mbr_bl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mbr_bl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mbr_bl_y = value

    @builtins.property
    def mbr_bl_z(self):
        """Message field 'mbr_bl_z'."""
        return self._mbr_bl_z

    @mbr_bl_z.setter
    def mbr_bl_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mbr_bl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mbr_bl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mbr_bl_z = value

    @builtins.property
    def mbr_tr_x(self):
        """Message field 'mbr_tr_x'."""
        return self._mbr_tr_x

    @mbr_tr_x.setter
    def mbr_tr_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mbr_tr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mbr_tr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mbr_tr_x = value

    @builtins.property
    def mbr_tr_y(self):
        """Message field 'mbr_tr_y'."""
        return self._mbr_tr_y

    @mbr_tr_y.setter
    def mbr_tr_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mbr_tr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mbr_tr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mbr_tr_y = value

    @builtins.property
    def mbr_tr_z(self):
        """Message field 'mbr_tr_z'."""
        return self._mbr_tr_z

    @mbr_tr_z.setter
    def mbr_tr_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'mbr_tr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'mbr_tr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._mbr_tr_z = value

    @builtins.property
    def facing(self):
        """Message field 'facing'."""
        return self._facing

    @facing.setter
    def facing(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'facing' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'facing' field must be an integer in [-128, 127]"
        self._facing = value

    @builtins.property
    def lightstate(self):
        """Message field 'lightstate'."""
        return self._lightstate

    @lightstate.setter
    def lightstate(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lightstate' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'lightstate' field must be an integer in [-128, 127]"
        self._lightstate = value

    @builtins.property
    def signmain_val0(self):
        """Message field 'signmain_val0'."""
        return self._signmain_val0

    @signmain_val0.setter
    def signmain_val0(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'signmain_val0' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'signmain_val0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._signmain_val0 = value

    @builtins.property
    def signmain_val1(self):
        """Message field 'signmain_val1'."""
        return self._signmain_val1

    @signmain_val1.setter
    def signmain_val1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'signmain_val1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'signmain_val1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._signmain_val1 = value

    @builtins.property
    def signsuppl1_val0(self):
        """Message field 'signsuppl1_val0'."""
        return self._signsuppl1_val0

    @signsuppl1_val0.setter
    def signsuppl1_val0(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'signsuppl1_val0' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'signsuppl1_val0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._signsuppl1_val0 = value

    @builtins.property
    def signsuppl1_val1(self):
        """Message field 'signsuppl1_val1'."""
        return self._signsuppl1_val1

    @signsuppl1_val1.setter
    def signsuppl1_val1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'signsuppl1_val1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'signsuppl1_val1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._signsuppl1_val1 = value

    @builtins.property
    def signsuppl2_val0(self):
        """Message field 'signsuppl2_val0'."""
        return self._signsuppl2_val0

    @signsuppl2_val0.setter
    def signsuppl2_val0(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'signsuppl2_val0' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'signsuppl2_val0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._signsuppl2_val0 = value

    @builtins.property
    def signsuppl2_val1(self):
        """Message field 'signsuppl2_val1'."""
        return self._signsuppl2_val1

    @signsuppl2_val1.setter
    def signsuppl2_val1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'signsuppl2_val1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'signsuppl2_val1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._signsuppl2_val1 = value
