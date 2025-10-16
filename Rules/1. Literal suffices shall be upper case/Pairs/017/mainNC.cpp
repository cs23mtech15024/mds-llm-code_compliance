// ------ Non-Compliant (Seed 017)
// Context: Robotics motion control — PID gains and tick-to-meter conversion.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f' on float literals, 'l' on long, and 'u' on unsigned hex.

#include <iostream>
#include <iomanip>
#include <cmath>

struct PID {
    float kp;
    float ki;
    float kd;
    float integ;
    float prev_err;

    PID(float p, float i, float d) : kp(p), ki(i), kd(d), integ(0.0f), prev_err(0.0f) {}

    float step(float setpoint, float measured, float dt) {
        float err = setpoint - measured;
        integ += err * dt;
        float deriv = (err - prev_err) / dt;
        prev_err = err;
        return kp * err + ki * integ + kd * deriv;
    }
};

int main() {
    // Encoder/timing constants (non-compliant suffixes)
    const long  TICKS_PER_REV = 2048l;   // 'l' non-compliant
    const float WHEEL_CIRCUM  = 0.314f;  // 'f' non-compliant (meters)
    const float DT            = 0.01f;   // control loop period (s)
    const unsigned mask       = 0xffu;   // 'u' non-compliant (demo use)

    // PID gains (non-compliant lowercase 'f')
    PID pid(0.6f, 0.05f, 0.0f);

    // Simulated measurements: ticks per DT -> linear velocity estimate
    long tick_delta = 256l; // 'l' non-compliant
    float revs = static_cast<float>(tick_delta) / static_cast<float>(TICKS_PER_REV);
    float distance = revs * WHEEL_CIRCUM;
    float velocity = distance / DT;

    // Target velocity in m/s
    float setpoint = 1.20f;

    // Apply simple saturation using mask (artificial example to keep structure)
    unsigned clipped = static_cast<unsigned>(std::fmin(velocity * 100.0f, 255.0f)) & mask;
    float sensed = static_cast<float>(clipped) / 100.0f;

    float control = pid.step(setpoint, sensed, DT);

    std::cout << std::fixed << std::setprecision(3)
              << "v_meas=" << sensed << " m/s, u=" << control << "\n";
    return 0;
}