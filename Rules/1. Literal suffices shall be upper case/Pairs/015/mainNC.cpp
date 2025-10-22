// ------ Non-Compliant (Seed 015)
// Context: Robotics PID controller step simulation with tuning constants.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lower-case suffixes used: 0.01f, 1000ul, 5ll, 5000ull.

#include <iostream>
#include <iomanip>
#include <algorithm>

class PID {
    float kp_, ki_, kd_;
    float dt_;           // sample period
    float integral_;
    long long d_window_; // derivative window samples
    unsigned long integral_cap_;
public:
    PID(float kp, float ki, float kd)
        : kp_(kp),
          ki_(ki),
          kd_(kd),
          dt_(0.01f),           // non-compliant (should be 0.01F)
          integral_(0.0f),
          d_window_(5ll),        // non-compliant (should be 5LL)
          integral_cap_(1000ul)  // non-compliant (should be 1000UL)
    {}

    float step(float setpoint, float meas) {
        float error = setpoint - meas;
        integral_ += error * dt_;
        // clamp integral to prevent windup
        if (integral_ > static_cast<float>(integral_cap_)) {
            integral_ = static_cast<float>(integral_cap_);
        } else if (integral_ < -static_cast<float>(integral_cap_)) {
            integral_ = -static_cast<float>(integral_cap_);
        }
        // simple finite-difference derivative using window count (mocked here)
        float derivative = (error - prev_error_) / (dt_ * static_cast<float>(d_window_));
        prev_error_ = error;

        float out = kp_ * error + ki_ * integral_ + kd_ * derivative;
        // saturate output to a hypothetical actuator range
        const unsigned long long max_cmd = 5000ull; // non-compliant (should be 5000ULL)
        if (out > static_cast<float>(max_cmd)) out = static_cast<float>(max_cmd);
        if (out < 0.0f) out = 0.0f; // keep non-negative for this demo
        return out;
    }
private:
    float prev_error_ = 0.0f;
};

int main() {
    PID pid(1.2f, 0.4f, 0.05f); // lower-case 'f' suffixes are also non-compliant
    float sp = 100.0f;
    float y  = 0.0f;
    for (int i = 0; i < 10; ++i) {
        float u = pid.step(sp, y);
        y += u * 0.001f; // plant response (toy)
        std::cout << std::fixed << std::setprecision(2)
                  << "Iter " << i << ": u=" << u << " y=" << y << "\n";
    }
    return 0;
}