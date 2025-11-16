// Context: Machine tool spindle RPM limiter header

// seed_048_NC.h
#pragma once
int seed048_rpm_limit = 12000;
bool seed048_is_allowed(int rpm) {
    return rpm <= seed048_rpm_limit;
}
