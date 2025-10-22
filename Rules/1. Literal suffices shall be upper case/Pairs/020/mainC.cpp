// ------ Compliant (Seed 020)
// Context: Robotics — simple PID controller over a fixed horizon.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes changed to uppercase F, U, and L.

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
    // PID gains (compliant 'F' suffixes)
    PID pid{0.8F, 0.1F, 0.05F, 0.0F, 0.0F};

    // Fixed timestep and horizon (compliant 'F', 'U', 'L')
    const float dt = 0.01F;     // compliant
    const unsigned N = 10U;     // compliant
    const long cycles = 1L;     // compliant
    (void)cycles;

    const float setpoint = 1.0F; // target position (compliant)
    std::array<float, 10> meas{0.0F, 0.2F, 0.35F, 0.5F, 0.62F,
                               0.72F, 0.80F, 0.86F, 0.91F, 0.94F};

    std::array<float, 10> control{};
    for (unsigned i = 0U; i < N; ++i) { // compliant
        const float err = setpoint - meas[i];
        pid.integral += err * dt;
        const float deriv = (err - pid.prev_err) / dt;
        const float u = pid.kp * err + pid.ki * pid.integral + pid.kd * deriv;
        pid.prev_err = err;

        // Clamp output (uses 0.0F and 1.0F compliantly)
        float v = u;
        if (v < 0.0F) v = 0.0F;
        if (v > 1.0F) v = 1.0F;
        control[i] = v;
    }

    std::cout << "Control:";
    for (unsigned i = 0U; i < N; ++i) { // compliant
        std::cout << ' ' << control[i];
    }
    std::cout << '\n';
    return 0;
}