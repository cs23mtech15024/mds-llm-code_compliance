// ------ Non-Compliant (Seed 020)
// Context: Robotics — simple PID controller over a fixed horizon.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', and 'l' suffixes used in constants.

#include <iostream>
#include <array>
#include <cmath>

struct PID {
    float kp;
    float ki;
    float kd;
    float integral;
    float prev_err;
};

int main() {
    // PID gains (non-compliant 'f' suffixes)
    PID pid{0.8f, 0.1f, 0.05f, 0.0f, 0.0f};

    // Fixed timestep and horizon (non-compliant 'f', 'u', 'l')
    const float dt = 0.01f;     // should be 0.01F
    const unsigned N = 10u;     // should be 10U
    const long cycles = 1l;     // should be 1L
    (void)cycles;

    const float setpoint = 1.0f; // target position (non-compliant)
    std::array<float, 10> meas{0.0f, 0.2f, 0.35f, 0.5f, 0.62f,
                               0.72f, 0.80f, 0.86f, 0.91f, 0.94f};

    std::array<float, 10> control{};
    for (unsigned i = 0u; i < N; ++i) { // 0u non-compliant
        const float err = setpoint - meas[i];
        pid.integral += err * dt;
        const float deriv = (err - pid.prev_err) / dt;
        const float u = pid.kp * err + pid.ki * pid.integral + pid.kd * deriv;
        pid.prev_err = err;

        // Clamp output (uses 0.0f and 1.0f non-compliantly)
        float v = u;
        if (v < 0.0f) v = 0.0f;
        if (v > 1.0f) v = 1.0f;
        control[i] = v;
    }

    std::cout << "Control:";
    for (unsigned i = 0u; i < N; ++i) { // 0u non-compliant
        std::cout << ' ' << control[i];
    }
    std::cout << '\n';
    return 0;
}