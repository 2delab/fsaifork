#!/usr/bin/env python3
"""
FSAI Teleop Node — keyboard + joystick support
================================================

Usage:
    ros2 run teleop_keyboard teleop_node                        # keyboard (default)
    ros2 run teleop_keyboard teleop_node --ros-args -p device:=keyboard
    ros2 run teleop_keyboard teleop_node --ros-args -p device:=joystick
    ros2 run teleop_keyboard teleop_node --ros-args -p device:=joystick -p js_device:=/dev/input/js0

Genius Turbo joystick mapping (confirmed from joystick_test.py):
    Axis 1  → Throttle/Brake  (push forward = gas, pull back = brake / reverse)
    Axis 2  → Steering        (left = -1.0, right = +1.0)

    Button 0 (Trigger) → FAST steer: cap 0.9 rad vs normal 0.6 rad (hold, live)
    Button 1 (Thumb)   → Reverse modifier (hold while pulling back for reverse gear)
    Button 2 (Top2)    → Steer RIGHT (hold to ramp, release to centre)
    Button 3 (Top3)    → Steer LEFT  (hold to ramp, release to centre)

Keyboard controls:
    i / k  : increase / decrease speed
    j / l  : steer left / right
    space  : hard brake
    q      : quit

Throttle axis behaviour:
    Push forward (filtered < 0) → drive forward (gas scales 0→1 over ~33% stick)
    Pull back (filtered > 0)    → instant BRAKE  (unless Thumb held → reverse gas)
    Release Thumb mid pull-back → immediate brake (handled in button event)
    Rest / deadzone             → coast (no gas, no brake)
"""

import rclpy
from rclpy.node import Node

import sys
import struct
import os
import glob
import threading
import termios
import tty
import select

from vehiclecontrol_msgs.msg import VehicleControl
from nav_msgs.msg import Odometry

# ── Constants ──────────────────────────────────────────────────────────────────
KEYBOARD_HELP = """
Control The FSAI Car!  [KEYBOARD MODE]
--------------------------------------
Moving around:
        i
   j    k    l
        ,
   space - Hard Brake

i/k : increase/decrease speed
j/l : steer left/right
r   : toggle reverse
, or space : Hard Brake (Stop)
q  : quit
CTRL-C to quit
"""

JS_EVENT_FMT  = "IhBB"
JS_EVENT_SIZE = struct.calcsize(JS_EVENT_FMT)
JS_EVENT_BUTTON = 0x01
JS_EVENT_AXIS   = 0x02
JS_EVENT_INIT   = 0x80

# Genius Turbo (device:=joystick) axis & button indices
GENIUS_AXIS_STEER    = 2
GENIUS_AXIS_THROTTLE = 1
GENIUS_BTN_TRIGGER   = 0   # Fast steer cap
GENIUS_BTN_THUMB     = 1   # Reverse modifier
GENIUS_BTN_TOP2      = 2   # Steer right
GENIUS_BTN_TOP3      = 3   # Steer left

# Saitek ST90 (device:=saitek) axis & button indices
SAITEK_AXIS_STEER    = 0   # X-Axis (Left/Right)
SAITEK_AXIS_THROTTLE = 1   # Y-Axis (Forward/Back)
SAITEK_BTN_TRIGGER   = 0   # Fast steer cap modifier
SAITEK_BTN_REV       = 1   # Reverse mode toggle / modifier
SAITEK_BTN_BRAKE     = 2   # Emergency Brake

# Deadzones
JS_DEADZONE = 0.15


# ── Helpers ────────────────────────────────────────────────────────────────────

def normalise_axis(raw: int) -> float:
    return raw / 32767.0


def apply_deadzone(value: float, deadzone: float) -> float:
    if abs(value) < deadzone:
        return 0.0
    sign = 1.0 if value > 0 else -1.0
    return sign * (abs(value) - deadzone) / (1.0 - deadzone)


def find_joystick() -> str:
    devices = sorted(glob.glob("/dev/input/js*"))
    if not devices:
        raise FileNotFoundError("No joystick found in /dev/input/js*")
    return devices[0]


# ── Main ROS 2 Node ────────────────────────────────────────────────────────────

class TeleopNode(Node):
    def __init__(self):
        super().__init__('teleop_node')

        # ── Parameters ──
        self.declare_parameter('device',    'keyboard')        # 'keyboard' | 'joystick' | 'saitek'
        self.declare_parameter('js_device', '/dev/input/js0')

        self.device    = self.get_parameter('device').get_parameter_value().string_value
        self.js_device = self.get_parameter('js_device').get_parameter_value().string_value

        self.declare_parameter('mode', 'normal')        # 'normal' | 'mapping'
        self.declare_parameter('speed_target', 5.0)     # Target speed in m/s
        self.declare_parameter('max_gas_mapping', 0.3)  # Fallback gas cap if no odometry

        self.mode            = self.get_parameter('mode').get_parameter_value().string_value.lower()
        self.speed_target    = self.get_parameter('speed_target').get_parameter_value().double_value
        self.max_gas_mapping = self.get_parameter('max_gas_mapping').get_parameter_value().double_value

        # ── Publisher ──
        self.cmd_pub = self.create_publisher(VehicleControl, '/carmaker/VehicleControl', 10)

        # ── Speed Subscriber (Mapping Mode) ──
        self.current_speed = 0.0
        self.speed_active  = False
        self.err_sum       = 0.0   # Integral error for PI controller
        if self.mode == 'mapping':
            self.create_subscription(Odometry, '/carmaker/odom', self._odom_cb, 10)

        # ── Shared state ──
        self.gas   = 0.0
        self.brake = 0.0
        self.steer = 0.0
        self._lock = threading.Lock()

        # ── Control params ──
        self.gas_step        = 0.05
        self.steer_step      = 0.1          # keyboard: per key-press
        self.steer_ramp_rate = 0.06         # joystick buttons: rad/tick
        self.max_gas         = 1.0
        self.max_steer       = 0.6          # normal cap  (~34°)
        self.max_steer_fast  = 0.9          # fast cap    (~52°)

        # ── Joystick button flags ──
        self.steer_left_held  = False   
        self.steer_right_held = False   
        self.steer_rate_fast  = False   

        # ── Throttle context ──
        self.thumb_held    = False   
        self.last_throttle = 0.0    
        self.reverse_mode  = False  

        # ── Publish timer (50 Hz) ──
        self.timer = self.create_timer(0.02, self.publish_command)

        self.get_logger().info(f"Teleop started in [{self.device.upper()}] mode")
        if self.mode == 'mapping':
            self.get_logger().info(f"*** MAPPING MODE ACTIVE — Max Gas Scale capped at {self.max_gas_mapping * 100}% ***")

    # ──────────────────────────────────────────────────────────────────────────
    def _odom_cb(self, msg: Odometry):
        # Calculate forward speed magnitude directly from twist
        vx = msg.twist.twist.linear.x
        vy = msg.twist.twist.linear.y
        with self._lock:
            self.current_speed = (vx**2 + vy**2)**0.5
            self.speed_active  = True

    # ──────────────────────────────────────────────────────────────────────────
    def publish_command(self):
        with self._lock:
            # Only apply ramping for keyboard/Genius. Saitek uses direct analog overriding.
            if self.device != 'saitek':
                if self.steer_rate_fast:
                    rate = self.steer_ramp_rate * 1.5   
                    cap  = self.max_steer_fast
                else:
                    rate = self.steer_ramp_rate          
                    cap  = self.max_steer

                if self.steer_left_held and not self.steer_right_held:
                    self.steer = max(self.steer - rate, -cap)
                elif self.steer_right_held and not self.steer_left_held:
                    self.steer = min(self.steer + rate,  cap)
                else:
                    self.steer = 0.0

            gas, brake, steer = self.gas, self.brake, self.steer
            selector = -1 if self.reverse_mode else 1
            
            # --- Mapping Mode Hard Cap ---
            if self.mode == 'mapping' and selector == 1 and gas > 0:
                gas = min(gas, self.max_gas_mapping)

        msg = VehicleControl()
        msg.use_vc        = True
        msg.selector_ctrl = selector
        msg.gas           = float(gas)
        msg.brake         = float(brake)
        msg.steer_ang     = float(steer)
        msg.steer_ang_vel = 0.0
        msg.steer_ang_acc = 0.0
        self.cmd_pub.publish(msg)

    # ──────────────────────────────────────────────────────────────────────────
    def set_state(self, gas=None, brake=None, steer=None):
        with self._lock:
            if gas   is not None: self.gas   = gas
            if brake is not None: self.brake = brake
            if steer is not None: self.steer = steer

    def zero_all(self):
        with self._lock:
            self.gas   = 0.0
            self.brake = 1.0
            self.steer = 0.0
            self.steer_left_held = False
            self.steer_right_held = False


# ── Keyboard driver ────────────────────────────────────────────────────────────

def run_keyboard(node: TeleopNode):
    if not sys.stdin.isatty():
        node.get_logger().error(
            "Keyboard mode requires a real terminal. "
            "Run with: ros2 run teleop_keyboard teleop_node"
        )
        return

    settings = termios.tcgetattr(sys.stdin)
    print(KEYBOARD_HELP)

    def get_key():
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        key = sys.stdin.read(1) if rlist else ''
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        return key

    try:
        while rclpy.ok():
            key = get_key()
            with node._lock:
                rev = " [REV]" if node.reverse_mode else ""
                if key == 'i':
                    node.gas   = min(node.gas + node.gas_step, node.max_gas)
                    node.brake = 0.0
                    print(f"  Gas: {node.gas:.2f}  Steer: {node.steer:.2f}{rev}\r")
                elif key == 'k':
                    node.gas   = max(node.gas - node.gas_step, 0.0)
                    print(f"  Gas: {node.gas:.2f}  Steer: {node.steer:.2f}{rev}\r")
                elif key == 'j':
                    node.steer = min(node.steer + node.steer_step, node.max_steer)
                    print(f"  Gas: {node.gas:.2f}  Steer: {node.steer:.2f}{rev}\r")
                elif key == 'l':
                    node.steer = max(node.steer - node.steer_step, -node.max_steer)
                    print(f"  Gas: {node.gas:.2f}  Steer: {node.steer:.2f}{rev}\r")
                elif key == 'r':
                    node.reverse_mode = not node.reverse_mode
                    node.gas   = 0.0
                    node.brake = 1.0
                    label = "[REVERSE]" if node.reverse_mode else "[FORWARD]"
                    print(f"  {label}\r")
                elif key in (' ', ','):
                    node.gas   = 0.0
                    node.brake = 1.0
                    node.steer = 0.0
                    print("  BRAKE APPLIED\r")
                elif key in ('q', '\x03'):
                    break

            rclpy.spin_once(node, timeout_sec=0.1)

    finally:
        node.zero_all()
        node.publish_command()
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)


# ── Genius Turbo Joystick driver ───────────────────────────────────────────────

def run_joystick(node: TeleopNode):
    js_path = node.js_device

    if not os.path.exists(js_path):
        try:
            js_path = find_joystick()
            node.get_logger().warn(
                f"/dev/input/js0 not found, using {js_path} instead"
            )
        except FileNotFoundError as e:
            node.get_logger().fatal(str(e))
            return

    node.get_logger().info(f"Joystick device: {js_path}")
    print(f"""
Joystick Teleop — Genius Turbo  [{js_path}]
-------------------------------------------
  Stick Y (Axis 1)  → Push forward          = drive forward
                      Pull back (no Thumb)   = INSTANT BRAKE
                      Pull back + Thumb hold = REVERSE gear
                      Release Thumb mid-pull = INSTANT BRAKE
                      Rest / centre          = coast
  Top3    (Btn 3)   → Steer LEFT  (hold to ramp, release to centre)
  Top2    (Btn 2)   → Steer RIGHT (hold to ramp, release to centre)
  Trigger (Btn 0)   → FAST steer: cap 0.9 rad vs normal 0.6 rad (hold, live)
  Thumb   (Btn 1)   → Hold for REVERSE (while pulling back)
  q + Enter         → Quit
""")

    try:
        with open(js_path, "rb") as js:
            while rclpy.ok():
                raw = js.read(JS_EVENT_SIZE)
                if len(raw) < JS_EVENT_SIZE:
                    break

                time_ms, value, ev_type, number = struct.unpack(JS_EVENT_FMT, raw)
                is_init = bool(ev_type & JS_EVENT_INIT)
                ev_type &= ~JS_EVENT_INIT

                if ev_type == JS_EVENT_AXIS:
                    norm     = normalise_axis(value)
                    filtered = apply_deadzone(norm, JS_DEADZONE)

                    if number == GENIUS_AXIS_THROTTLE:
                        with node._lock:
                            node.last_throttle = filtered
                            thumb = node.thumb_held

                        if filtered < 0.0:        # push forward
                            gas   = min(-filtered * 3.0, 1.0)
                            brake = 0.0
                            with node._lock:
                                node.reverse_mode = False
                            node.set_state(gas=gas, brake=brake)

                        elif filtered > 0.0:      # pull back
                            if thumb:
                                gas   = min(filtered * 3.0, 1.0)
                                brake = 0.0
                                with node._lock:
                                    node.reverse_mode = True
                                node.set_state(gas=gas, brake=brake)
                            else:
                                gas, brake = 0.0, 1.0
                                with node._lock:
                                    node.reverse_mode = False
                                node.set_state(gas=gas, brake=brake)

                        else:                     # rest
                            gas, brake = 0.0, 0.0
                            with node._lock:
                                node.reverse_mode = False
                            node.set_state(gas=gas, brake=brake)

                        if not is_init:
                            rev = " [REVERSE]" if node.reverse_mode else ""
                            print(f"  Gas: {gas:.2f}  Brake: {brake:.2f}{rev}  Steer: {node.steer:+.2f}\r", end='')

                elif ev_type == JS_EVENT_BUTTON:
                    if number == GENIUS_BTN_TRIGGER:       
                        with node._lock:
                            node.steer_rate_fast = bool(value)
                        mode = "FAST STEER — cap 0.9 rad (1.5×)" if value else "Normal steer — cap 0.6 rad"
                        print(f"\r  {mode:<50}", flush=True)

                    elif number == GENIUS_BTN_THUMB:       
                        with node._lock:
                            node.thumb_held = bool(value)
                            throttle = node.last_throttle
                        if not value and throttle > 0.0:
                            node.set_state(gas=0.0, brake=1.0)
                            with node._lock:
                                node.reverse_mode = False
                            print(f"\r  {'Thumb released → INSTANT BRAKE':<50}", flush=True)
                        else:
                            mode = "[THUMB] Pull back for REVERSE" if value else "Thumb released"
                            print(f"\r  {mode:<50}", flush=True)

                    elif number == GENIUS_BTN_TOP2:        
                        with node._lock:
                            node.steer_right_held = bool(value)
                            if not value:
                                node.steer = 0.0
                        direction = "-> STEER RIGHT hold" if value else "steer right released - centred"
                        print(f"\r  {direction:<45}", flush=True)
                        node.publish_command()

                    elif number == GENIUS_BTN_TOP3:        
                        with node._lock:
                            node.steer_left_held = bool(value)
                            if not value:
                                node.steer = 0.0
                        direction = "<- STEER LEFT hold" if value else "steer left released - centred"
                        print(f"\r  {direction:<45}", flush=True)
                        node.publish_command()

                rclpy.spin_once(node, timeout_sec=0.0)

    except PermissionError:
        node.get_logger().fatal("Permission denied on joystick")
    except FileNotFoundError:
        node.get_logger().fatal(f"Device not found: {js_path}")
    finally:
        node.zero_all()
        try:
            node.publish_command()
        except Exception:
            pass


# ── Saitek ST90 Analog Joystick driver ─────────────────────────────────────────

def run_saitek(node: TeleopNode):
    js_path = node.js_device

    if not os.path.exists(js_path):
        try:
            js_path = find_joystick()
            node.get_logger().warn(
                f"/dev/input/js0 not found, using {js_path} instead"
            )
        except FileNotFoundError as e:
            node.get_logger().fatal(str(e))
            return

    node.get_logger().info(f"Saitek device bound at: {js_path}")
    print(f"""
Joystick Teleop — Saitek ST90 Analog [{js_path}]
------------------------------------------------
  Stick X (Axis 0)  → Analog Steering (Left/Right limit ±0.6 rad)
                      Hold Trigger for Fast limit ±0.9 rad
  Stick Y (Axis 1)  → Push forward  = Analog Drive Forward
                      Pull back     = Analog Brake
  Button 1          → Hold = Reverse Mode
  Button 2          → INSTANT EMERGENCY BRAKE
  Trigger (Btn 0)   → FAST steer cap
  q + Enter         → Quit
""")

    try:
        with open(js_path, "rb") as js:
            while rclpy.ok():
                raw = js.read(JS_EVENT_SIZE)
                if len(raw) < JS_EVENT_SIZE:
                    break

                time_ms, value, ev_type, number = struct.unpack(JS_EVENT_FMT, raw)
                is_init = bool(ev_type & JS_EVENT_INIT)
                ev_type &= ~JS_EVENT_INIT

                # Emergency Brake check override (Btn 2)
                with node._lock:
                    hard_brake = node.steer_right_held  # repurposing flag for hacky hard brake

                if ev_type == JS_EVENT_AXIS:
                    norm     = normalise_axis(value)
                    filtered = apply_deadzone(norm, JS_DEADZONE)

                    if number == SAITEK_AXIS_STEER:
                        with node._lock:
                            limit = node.max_steer_fast if node.steer_rate_fast else node.max_steer
                            # Invert mapping and apply a quadratic curve for high-speed stability.
                            # Small stick movements = very small steering. Max stick = max steering. 
                            steer_curve = filtered * abs(filtered)
                            node.steer = -steer_curve * limit

                    elif number == SAITEK_AXIS_THROTTLE:
                        if hard_brake:
                            pass # Ignored during emergency brake
                        else:
                            # Scale joystick strictly to mode limits (e.g., 0.20 max in mapping)
                            gas_limit = node.max_gas_mapping if node.mode == 'mapping' else 1.0
                            
                            if filtered < 0.0:        # push forward
                                gas   = min(-filtered * gas_limit * 1.5, gas_limit)
                                brake = 0.0
                                with node._lock:
                                    node.gas = gas
                                    node.brake = brake
                            elif filtered > 0.0:      # pull back
                                with node._lock:
                                    rev_mode = node.thumb_held # Repurposing flag for Btn 1 reverse hold
                                if rev_mode:
                                    gas   = min(filtered * gas_limit * 1.5, gas_limit)
                                    brake = 0.0
                                    with node._lock:
                                        node.gas = gas
                                        node.brake = brake
                                        node.reverse_mode = True
                                else:
                                    # Regular braking
                                    gas = 0.0
                                    brake = min(filtered * 2.0, 1.0)
                                    with node._lock:
                                        node.gas = gas
                                        node.brake = brake
                                        node.reverse_mode = False
                            else:                     # deadzone rest
                                with node._lock:
                                    node.gas = 0.0
                                    node.brake = 0.0
                                    node.reverse_mode = False

                    if not is_init:
                        rev = " [REVERSE]" if node.reverse_mode else ""
                        brk = " !!HARD BRAKE!!" if hard_brake else ""
                        print(f"  Gas: {node.gas:.2f}  Brake: {node.brake:.2f}{rev}{brk}  Steer: {node.steer:+.2f}\r", end='')

                elif ev_type == JS_EVENT_BUTTON:
                    if number == SAITEK_BTN_TRIGGER:       
                        with node._lock:
                            node.steer_rate_fast = bool(value)
                        mode = "FAST STEER CAP [±0.9 rad]" if value else "Normal steer cap [±0.6 rad]"
                        print(f"\r  {mode:<50}", flush=True)
                        # Re-publish active steering value to instantly feel new cap
                        with node._lock:
                            norm = normalise_axis(0) # Get cached physical tilt via axis event queue if possible
                            # For now just let the next axis tick handle the transition smooth

                    elif number == SAITEK_BTN_REV:       
                        with node._lock:
                            node.thumb_held = bool(value)
                        mode = "[REVERSE MODE ACTIVE]" if value else "Forward drive"
                        print(f"\r  {mode:<50}", flush=True)

                    elif number == SAITEK_BTN_BRAKE:        
                        with node._lock:
                            node.steer_right_held = bool(value)
                            if value:
                                node.gas = 0.0
                                node.brake = 1.0
                        direction = ">>> EMERGENCY BRAKE <<<" if value else "Brake released"
                        print(f"\r  {direction:<45}", flush=True)

                # Fast ticks for analog
                rclpy.spin_once(node, timeout_sec=0.0)

    except PermissionError:
        node.get_logger().fatal("Permission denied on joystick")
    except FileNotFoundError:
        node.get_logger().fatal(f"Device not found: {js_path}")
    finally:
        node.zero_all()
        try:
            node.publish_command()
        except Exception:
            pass


# ── Entry point ────────────────────────────────────────────────────────────────

def main(args=None):
    rclpy.init(args=args)
    node = TeleopNode()

    device = node.device.lower()

    try:
        if device == 'keyboard':
            run_keyboard(node)
        elif device == 'joystick':
            run_joystick(node)
        elif device == 'saitek':
            run_saitek(node)
        else:
            node.get_logger().error(
                f"Unknown device '{device}'. Use 'keyboard', 'joystick', or 'saitek'."
            )
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == '__main__':
    main()
