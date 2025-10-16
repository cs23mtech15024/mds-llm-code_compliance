// ------ Non-Compliant (Seed 049)
// Context: Satellite Orientation Control — simulate PID-based pitch correction loop
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase 'f', 'u', 'l' suffixes in numeric literals.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct PIDConfig {
    float Kp;          // proportional gain
    float Ki;          // integral gain
    float Kd;          // derivative gain
    unsigned limit;    // max update count
    long baseTime;     // milliseconds
};

class PIDController {
public:
    PIDController(const PIDConfig& cfg)
        : cfg_(cfg), integral_(0.0f), prevError_(0.0f) {} // non-compliant

    float update(float target, float actual) {
        float error = target - actual;
        integral_ += error * 0.1f; // non-compliant
        float derivative = (error - prevError_) / 0.1f; // non-compliant
        prevError_ = error;
        return cfg_.Kp * error + cfg_.Ki * integral_ + cfg_.Kd * derivative;
    }

private:
    PIDConfig cfg_;
    float integral_;
    float prevError_;
};

int main() {
    PIDConfig cfg{0.8f, 0.05f, 0.02f, 100u, 10000l}; // non-compliant
    PIDController pid(cfg);

    float targetPitch = 5.0f; // degrees (non-compliant)
    float currentPitch = 0.0f;

    for (unsigned i = 0u; i < cfg.limit; ++i) { // non-compliant
        float control = pid.update(targetPitch, currentPitch);
        currentPitch += control * 0.1f; // non-compliant
        std::cout << "Step " << i << ": Pitch=" << std::fixed << std::setprecision(2)
                  << currentPitch << " deg\n";
        if (std::fabs(targetPitch - currentPitch) < 0.01f) break; // non-compliant
    }

    std::cout << "Simulation done at t=" << cfg.baseTime << " ms\n";
    return 0;
}