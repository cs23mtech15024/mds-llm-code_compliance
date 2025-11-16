// Context: Audio synthesizer detune factor table

// seed_047_NC.h
#pragma once
float seed047_detune = 0.03F;
float seed047_apply(float f) {
    return f + (f * seed047_detune);
}
