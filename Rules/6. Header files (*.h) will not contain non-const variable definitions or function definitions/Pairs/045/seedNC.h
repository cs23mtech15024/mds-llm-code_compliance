// Context: Smartwatch heart rate smoothing window

// seed_045_NC.h
#pragma once
int seed045_smooth_window = 6;
float seed045_smooth_hr(float* vals) {
    return vals[0];
}
