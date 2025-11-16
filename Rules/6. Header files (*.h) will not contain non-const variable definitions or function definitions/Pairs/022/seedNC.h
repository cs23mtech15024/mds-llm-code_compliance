// Context: Power meter calibration header defining gains

// seed_022_NC.h
#pragma once
double seed022_calibration_gain = 1.234;
double seed022_apply_gain(double v) {
    return v * seed022_calibration_gain;
}
