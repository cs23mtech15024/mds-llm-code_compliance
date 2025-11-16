// Context: Autonomous car lane deviation threshold header

// seed_086_NC.h
#pragma once
double seed086_lane_threshold = 0.35;
bool seed086_is_out(double d) {
    return d > seed086_lane_threshold;
}
