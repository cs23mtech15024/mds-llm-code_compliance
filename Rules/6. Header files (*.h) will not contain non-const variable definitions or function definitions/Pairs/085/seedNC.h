// Context: Biomedical oxygen saturation smoothing header

// seed_085_NC.h
#pragma once
float seed085_spo2_alpha = 0.6F;
float seed085_filter(float v) {
    return (v * seed085_spo2_alpha);
}
