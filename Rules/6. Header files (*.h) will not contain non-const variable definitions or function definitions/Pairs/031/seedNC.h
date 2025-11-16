// Context: Thermal camera gain configuration

// seed_031_NC.h
#pragma once
float seed031_gain = 1.75F;
float seed031_apply_gain(float x) {
    return x * seed031_gain;
}
