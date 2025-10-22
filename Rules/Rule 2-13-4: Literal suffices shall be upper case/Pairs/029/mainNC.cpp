// ------ Non-Compliant (Seed 029)
// Context: Robotics — simple PID speed controller simulation for a motor.
//          Demonstrates proportional/integral/derivative gains and limits.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f'/'u' suffixes for literals and lowercase hex digits in a mask.

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <iomanip>

struct PID {
    float kp;
    float ki;
    float kd;
    float integral;
    float prev_error;
};

static uint16_t statusMask(uint16_t flags) {
    const uint16_t mask = 0x00ffu; // non-compliant (lowercase hex digits + 'u')
    return static_cast<uint16_t>(flags & mask);
}

static float clamp(float v, float lo, float hi) {
    return std::max(lo, std::min(hi, v));
}

int main() {
    // Non-compliant literals ('f', 'u')
    PID pid{0.8f, 0.05f, 0.02f, 0.0f, 0.0f}; // gains and state
    const float dt = 0.01f;   // 10 ms
    const float out_min = -1.0f;
    const float out_max =  1.0f;
    const unsigned steps = 200u; // simulation steps

    float setpoint = 100.0f; // target speed (RPM)
    float speed = 0.0f;      // measured speed

    uint16_t flags = 0x0134u; // some dummy status flags

    std::cout << "t(s), speed, control, flags\n";
    for (unsigned i = 0u; i < steps; ++i) {
        const float error = setpoint - speed;
        pid.integral += error * dt;
        const float derivative = (error - pid.prev_error) / dt;
        const float control = clamp(pid.kp * error + pid.ki * pid.integral + pid.kd * derivative,
                                    out_min, out_max);

        // Plant model (very simple first-order response)
        speed += (control * 50.0f - (speed - 0.0f) * 0.1f) * dt;

        pid.prev_error = error;

        const uint16_t masked = statusMask(flags);
        std::cout << std::fixed << std::setprecision(3)
                  << i * dt << ", " << speed << ", " << control
                  << ", 0x" << std::hex << masked << std::dec << "\n";
    }

    return 0;
}