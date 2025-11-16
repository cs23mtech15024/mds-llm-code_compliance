// Context: Robotic gripper force calibration header

// seed_093_NC.h
#pragma once
int seed093_force_offset = 12;
int seed093_calibrate(int f) {
    return f + seed093_force_offset;
}
