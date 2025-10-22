// ------ Compliant (Seed 049)
// Context: Satellite Orientation Control — simulate PID-based pitch correction loop
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: Changed all literal suffixes 'f', 'u', 'l' → 'F', 'U', 'L'.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct PIDConfig {
    float Kp;
    float Ki;
    float Kd;
    unsigned limit;
    long baseTime;
};

class PIDController {
public:
    PIDController(const PIDConfig& cfg)
        : cfg_(cfg), integral_(0.0F), prevError_(0.0F) {}

    float update(float target, float actual) {
        float error = target - actual;
        integral_ += error * 0.1F;
        float derivative = (error - prevError_) / 0.1F;
        prevError_ = error;
        return cfg_.Kp * error + cfg_.Ki * integral_ + cfg_.Kd * derivative;
    }

private:
    PIDConfig cfg_;
    float integral_;
    float prevError_;
};

int main() {
    PIDConfig cfg{0.8F, 0.05F, 0.02F, 100U, 10000L};
    PIDController pid(cfg);

    float targetPitch = 5.0F;
    float currentPitch = 0.0F;

    for (unsigned i = 0U; i < cfg.limit; ++i) {
        float control = pid.update(targetPitch, currentPitch);
        currentPitch += control * 0.1F;
        std::cout << "Step " << i << ": Pitch=" << std::fixed << std::setprecision(2)
                  << currentPitch << " deg\n";
        if (std::fabs(targetPitch - currentPitch) < 0.01F) break;
    }

    std::cout << "Simulation done at t=" << cfg.baseTime << " ms\n";
    return 0;
}