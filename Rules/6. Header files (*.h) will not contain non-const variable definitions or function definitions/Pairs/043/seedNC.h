// Context: Biosignal ECG threshold header

// seed_043_NC.h
#pragma once
float seed043_ecg_threshold = 0.45F;
bool seed043_is_peak(float v) {
    return v > seed043_ecg_threshold;
}
