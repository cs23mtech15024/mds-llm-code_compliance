// Context: Weather buoy wave-height calibration header

// seed_084_NC.h
#pragma once
float seed084_wave_scale = 1.12F;
float seed084_adjust_height(float h) {
    return h * seed084_wave_scale;
}
