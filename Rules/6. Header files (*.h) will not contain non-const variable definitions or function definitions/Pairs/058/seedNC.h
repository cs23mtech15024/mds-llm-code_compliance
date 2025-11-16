// Context: Autopilot yaw control gain header

// seed_058_NC.h
#pragma once
double seed058_yaw_gain = 0.75;
double seed058_compute(double err) {
    return err * seed058_yaw_gain;
}
