// Context: Audio DSP filter coefficients header

// seed_011_NC.h
#pragma once
// NC: filter coefficients defined and helper implemented in header
#include <cstddef>
float seed011_coeffs[5] = {0.2F,0.2F,0.2F,0.2F,0.2F}; // NC

float seed011_apply(float x) { // NC
    return x * seed011_coeffs[0];
}
