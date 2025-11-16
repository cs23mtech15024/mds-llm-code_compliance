// Context: Marine sonar gain compensation header

// seed_072_NC.h
#pragma once
float seed072_gain = 2.4F;
float seed072_apply_gain(float v) {
    return v * seed072_gain;
}
