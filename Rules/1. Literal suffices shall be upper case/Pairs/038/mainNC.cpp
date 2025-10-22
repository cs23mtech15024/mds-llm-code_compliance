// ------ Non-Compliant (Seed 038)
// Context: Embedded Systems — compute PWM duty cycle for motor control, simulate saturation, and masking.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0xffu.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>

struct PwmConfig {
    float duty_min;       // minimum duty cycle fraction
    float duty_max;       // maximum duty cycle fraction
    unsigned pwm_mask;    // mask for resolution bits
    long ticks_per_cycle; // number of timer ticks per PWM cycle
};

class PwmGenerator {
public:
    explicit PwmGenerator(const PwmConfig& cfg) : config(cfg) {}

    unsigned computeDutyTicks(float command) {
        // normalize input [0,1]
        if (command < 0.0f) command = 0.0f;     // non-compliant
        if (command > 1.0f) command = 1.0f;     // non-compliant
        float duty = config.duty_min + command * (config.duty_max - config.duty_min);
        unsigned ticks = static_cast<unsigned>(duty * static_cast<float>(config.ticks_per_cycle)); // non-compliant
        return ticks & config.pwm_mask;
    }

private:
    PwmConfig config;
};

int main() {
    PwmConfig cfg{0.05f, 0.95f, 0xffu, 1000l}; // non-compliant
    PwmGenerator gen(cfg);

    for (float cmd = 0.0f; cmd <= 1.0f; cmd += 0.25f) { // non-compliant
        unsigned t = gen.computeDutyTicks(cmd);
        std::cout << std::fixed << std::setprecision(2)
                  << "Cmd=" << cmd << " -> Ticks=" << t << "\n";
    }
    return 0;
}