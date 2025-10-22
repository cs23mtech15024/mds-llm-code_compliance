// ------ Compliant (Seed 017)
// Context: Robotics motion control — PID gains and tick-to-meter conversion.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: All literal suffixes uppercased (F, L, U) and hex digits uppercased.

#include <iostream>
#include <iomanip>
#include <cmath>

struct PID {
    float kp;
    float ki;
    float kd;
    float integ;
    float prev_err;

    PID(float p, float i, float d) : kp(p), ki(i), kd(d), integ(0.0F), prev_err(0.0F) {}

    float step(float setpoint, float measured, float dt) {
        float err = setpoint - measured;
        integ += err * dt;
        float deriv = (err - prev_err) / dt;
        prev_err = err;
        return kp * err + ki * integ + kd * deriv;
    }
};

int main() {
    // Encoder/timing constants (compliant suffixes)
    const long  TICKS_PER_REV = 2048L;   // 'L' compliant
    const float WHEEL_CIRCUM  = 0.314F;  // 'F' compliant (meters)
    const float DT            = 0.01F;   // control loop period (s)
    const unsigned mask       = 0XFFU;   // 'U' and uppercase hex digits

    // PID gains (compliant uppercase 'F')
    PID pid(0.6F, 0.05F, 0.0F);

    // Simulated measurements: ticks per DT -> linear velocity estimate
    long tick_delta = 256L; // 'L' compliant
    float revs = static_cast<float>(tick_delta) / static_cast<float>(TICKS_PER_REV);
    float distance = revs * WHEEL_CIRCUM;
    float velocity = distance / DT;

    // Target velocity in m/s
    float setpoint = 1.20F;

    // Apply simple saturation using mask (same logic)
    unsigned clipped = static_cast<unsigned>(std::fmin(velocity * 100.0F, 255.0F)) & mask;
    float sensed = static_cast<float>(clipped) / 100.0F;

    float control = pid.step(setpoint, sensed, DT);

    std::cout << std::fixed << std::setprecision(3)
              << "v_meas=" << sensed << " m/s, u=" << control << "\n";
    return 0;
}