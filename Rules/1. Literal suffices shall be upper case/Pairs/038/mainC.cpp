// ------ Compliant (Seed 038)
// Context: Embedded Systems — compute PWM duty cycle for motor control, simulate saturation, and masking.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: uppercase literal suffixes ('F','U','L') and uppercase hex digits (0XFFU).

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>

struct PwmConfig {
    float duty_min;
    float duty_max;
    unsigned pwm_mask;
    long ticks_per_cycle;
};

class PwmGenerator {
public:
    explicit PwmGenerator(const PwmConfig& cfg) : config(cfg) {}

    unsigned computeDutyTicks(float command) {
        if (command < 0.0F) command = 0.0F;     // compliant
        if (command > 1.0F) command = 1.0F;     // compliant
        float duty = config.duty_min + command * (config.duty_max - config.duty_min);
        unsigned ticks = static_cast<unsigned>(duty * static_cast<float>(config.ticks_per_cycle));
        return ticks & config.pwm_mask;
    }

private:
    PwmConfig config;
};

int main() {
    PwmConfig cfg{0.05F, 0.95F, 0XFFU, 1000L}; // compliant
    PwmGenerator gen(cfg);

    for (float cmd = 0.0F; cmd <= 1.0F; cmd += 0.25F) { // compliant
        unsigned t = gen.computeDutyTicks(cmd);
        std::cout << std::fixed << std::setprecision(2)
                  << "Cmd=" << cmd << " -> Ticks=" << t << "\n";
    }
    return 0;
}