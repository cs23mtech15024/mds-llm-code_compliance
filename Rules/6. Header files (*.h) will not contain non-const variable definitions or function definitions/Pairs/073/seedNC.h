// Context: Wind turbine blade pitch calibration

// seed_073_NC.h
#pragma once
double seed073_pitch_offset = 1.8;
double seed073_calibrate(double p) {
    return p + seed073_pitch_offset;
}
