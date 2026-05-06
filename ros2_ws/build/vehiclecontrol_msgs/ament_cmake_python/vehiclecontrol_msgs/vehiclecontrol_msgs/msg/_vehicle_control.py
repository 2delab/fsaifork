# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vehiclecontrol_msgs:msg/VehicleControl.idl
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


class Metaclass_VehicleControl(type):
    """Metaclass of message 'VehicleControl'."""

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
            module = import_type_support('vehiclecontrol_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vehiclecontrol_msgs.msg.VehicleControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_control
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_control
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_control
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_control
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_control

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VehicleControl(metaclass=Metaclass_VehicleControl):
    """Message class 'VehicleControl'."""

    __slots__ = [
        '_use_vc',
        '_selector_ctrl',
        '_gas',
        '_brake',
        '_steer_ang',
        '_steer_ang_vel',
        '_steer_ang_acc',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'use_vc': 'boolean',
        'selector_ctrl': 'int8',
        'gas': 'double',
        'brake': 'double',
        'steer_ang': 'double',
        'steer_ang_vel': 'double',
        'steer_ang_acc': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
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
        self.use_vc = kwargs.get('use_vc', bool())
        self.selector_ctrl = kwargs.get('selector_ctrl', int())
        self.gas = kwargs.get('gas', float())
        self.brake = kwargs.get('brake', float())
        self.steer_ang = kwargs.get('steer_ang', float())
        self.steer_ang_vel = kwargs.get('steer_ang_vel', float())
        self.steer_ang_acc = kwargs.get('steer_ang_acc', float())

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
        if self.use_vc != other.use_vc:
            return False
        if self.selector_ctrl != other.selector_ctrl:
            return False
        if self.gas != other.gas:
            return False
        if self.brake != other.brake:
            return False
        if self.steer_ang != other.steer_ang:
            return False
        if self.steer_ang_vel != other.steer_ang_vel:
            return False
        if self.steer_ang_acc != other.steer_ang_acc:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def use_vc(self):
        """Message field 'use_vc'."""
        return self._use_vc

    @use_vc.setter
    def use_vc(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'use_vc' field must be of type 'bool'"
        self._use_vc = value

    @builtins.property
    def selector_ctrl(self):
        """Message field 'selector_ctrl'."""
        return self._selector_ctrl

    @selector_ctrl.setter
    def selector_ctrl(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'selector_ctrl' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'selector_ctrl' field must be an integer in [-128, 127]"
        self._selector_ctrl = value

    @builtins.property
    def gas(self):
        """Message field 'gas'."""
        return self._gas

    @gas.setter
    def gas(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gas' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gas' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gas = value

    @builtins.property
    def brake(self):
        """Message field 'brake'."""
        return self._brake

    @brake.setter
    def brake(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'brake' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'brake' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._brake = value

    @builtins.property
    def steer_ang(self):
        """Message field 'steer_ang'."""
        return self._steer_ang

    @steer_ang.setter
    def steer_ang(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'steer_ang' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_ang' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_ang = value

    @builtins.property
    def steer_ang_vel(self):
        """Message field 'steer_ang_vel'."""
        return self._steer_ang_vel

    @steer_ang_vel.setter
    def steer_ang_vel(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'steer_ang_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_ang_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_ang_vel = value

    @builtins.property
    def steer_ang_acc(self):
        """Message field 'steer_ang_acc'."""
        return self._steer_ang_acc

    @steer_ang_acc.setter
    def steer_ang_acc(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'steer_ang_acc' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_ang_acc' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_ang_acc = value
