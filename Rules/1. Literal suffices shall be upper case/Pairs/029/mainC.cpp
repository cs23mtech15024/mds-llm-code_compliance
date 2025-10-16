// ------ Compliant (Seed 029)
// Context: Robotics — simple PID speed controller simulation for a motor.
//          Demonstrates proportional/integral/derivative gains and limits.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase ('F','U') and hex digits to uppercase.

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
    const uint16_t mask = 0X00FFU; // compliant (uppercase hex digits + 'U')
    return static_cast<uint16_t>(flags & mask);
}

static float clamp(float v, float lo, float hi) {
    return std::max(lo, std::min(hi, v));
}

int main() {
    // Compliant literals ('F', 'U')
    PID pid{0.8F, 0.05F, 0.02F, 0.0F, 0.0F}; // gains and state
    const float dt = 0.01F;   // 10 ms
    const float out_min = -1.0F;
    const float out_max =  1.0F;
    const unsigned steps = 200U; // simulation steps

    float setpoint = 100.0F; // target speed (RPM)
    float speed = 0.0F;      // measured speed

    uint16_t flags = 0X0134U; // some dummy status flags

    std::cout << "t(s), speed, control, flags\n";
    for (unsigned i = 0U; i < steps; ++i) {
        const float error = setpoint - speed;
        pid.integral += error * dt;
        const float derivative = (error - pid.prev_error) / dt;
        const float control = clamp(pid.kp * error + pid.ki * pid.integral + pid.kd * derivative,
                                    out_min, out_max);

        // Plant model (very simple first-order response)
        speed += (control * 50.0F - (speed - 0.0F) * 0.1F) * dt;

        pid.prev_error = error;

        const uint16_t masked = statusMask(flags);
        std::cout << std::fixed << std::setprecision(3)
                  << i * dt << ", " << speed << ", " << control
                  << ", 0x" << std::hex << masked << std::dec << "\n";
    }

    return 0;
}