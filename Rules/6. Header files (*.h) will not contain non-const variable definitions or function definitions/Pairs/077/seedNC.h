// Context: Medical heart rate smoothing factor

// seed_077_NC.h
#pragma once
float seed077_smooth_factor = 0.85F;
float seed077_smooth(float hr) {
    return hr * seed077_smooth_factor;
}
