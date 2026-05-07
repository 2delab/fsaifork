# CarMaker Vehicle Control message
# Allows sending throttle, brake, and steering commands to CarMaker

bool use_vc             # Must be true or CarMaker ignores everything

int8 selector_ctrl      # Gear: -9=Park, -1=Reverse, 0=Neutral, 1=Drive

float64 gas             # Throttle pedal [0.0 – 1.0]
float64 brake           # Brake pedal [0.0 – 1.0]

float64 steer_ang       # Steering angle [rad] (positive=left)
float64 steer_ang_vel   # Steering angular velocity [rad/s]
float64 steer_ang_acc   # Steering angular acceleration [rad/s²]
