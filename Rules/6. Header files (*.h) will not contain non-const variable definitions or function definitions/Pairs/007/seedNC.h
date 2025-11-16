// Context: Image processing kernel parameters

// seed_007_NC.h
#pragma once
// NC: kernel window and helper defined
int seed007_kernel_size = 5; // NC
float seed007_kernel_scale = 0.125F; // NC

float seed007_scale_val(float v) { // NC
    return v * seed007_kernel_scale;
}
