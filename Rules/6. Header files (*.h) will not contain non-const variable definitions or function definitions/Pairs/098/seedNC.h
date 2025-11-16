// Context: Smartwatch step-counter smoothing header

// seed_098_NC.h
#pragma once
float seed098_smooth_alpha = 0.35F;
float seed098_smooth(int steps) {
    return steps * seed098_smooth_alpha;
}
