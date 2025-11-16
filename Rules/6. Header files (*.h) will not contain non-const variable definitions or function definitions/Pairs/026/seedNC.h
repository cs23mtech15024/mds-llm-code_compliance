// Context: Real-time clock drift correction header

// seed_026_NC.h
#pragma once
double seed026_drift_ppm = -2.5;
double seed026_correct_time(double t) {
    return t + t * (seed026_drift_ppm / 1e6);
}
