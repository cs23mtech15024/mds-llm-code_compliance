// ------ Compliant (Seed 018)
// Context: Embedded sensor fusion — 1D Kalman Filter for noisy distance measurement.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes changed to uppercase F and L.

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
        : x(0.0F), p(1.0F), q(1E-3F), r(1E-2F), k(0.0F) {} // compliant suffixes

    float update(float measurement) {
        // Prediction
        p += q;
        // Measurement update
        k = p / (p + r);
        x = x + k * (measurement - x);
        p = (1.0F - k) * p;
        return x;
    }
};

int main() {
    KalmanFilter kf;
    const long NUM_SAMPLES = 10L; // compliant suffix

    float measurement = 10.0F;
    for (long i = 0L; i < NUM_SAMPLES; ++i) { // compliant
        measurement += 0.5F * std::sin(i * 0.3F);
        float est = kf.update(measurement);
        std::cout << std::fixed << std::setprecision(3)
                  << "Step " << i << ": meas=" << measurement
                  << ", est=" << est << "\n";
    }
    return 0;
}