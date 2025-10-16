// ------ Non-Compliant (Seed 018)
// Context: Embedded sensor fusion — 1D Kalman Filter for noisy distance measurement.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f' and 'l' suffixes used in constants.

#include <iostream>
#include <iomanip>
#include <cmath>

struct KalmanFilter {
    float x;   // state estimate
    float p;   // error covariance
    float q;   // process noise
    float r;   // measurement noise
    float k;   // Kalman gain

    KalmanFilter()
        : x(0.0f), p(1.0f), q(1e-3f), r(1e-2f), k(0.0f) {} // non-compliant suffixes

    float update(float measurement) {
        // Prediction
        p += q;
        // Measurement update
        k = p / (p + r);
        x = x + k * (measurement - x);
        p = (1.0f - k) * p;
        return x;
    }
};

int main() {
    KalmanFilter kf;
    const long NUM_SAMPLES = 10l; // non-compliant suffix

    float measurement = 10.0f;
    for (long i = 0l; i < NUM_SAMPLES; ++i) { // non-compliant
        measurement += 0.5f * std::sin(i * 0.3f);
        float est = kf.update(measurement);
        std::cout << std::fixed << std::setprecision(3)
                  << "Step " << i << ": meas=" << measurement
                  << ", est=" << est << "\n";
    }
    return 0;
}