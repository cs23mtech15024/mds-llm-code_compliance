// Context: 3D printer extrusion multiplier header

// seed_055_NC.h
#pragma once
float seed055_extrude_mult = 1.0F;
float seed055_scaled(float v) {
    return v * seed055_extrude_mult;
}
