// ------ Compliant (Seed 024)
// Context: Embedded Firmware — compute PWM compare value with deadtime and clamp,
//          using a hardware timer period and a duty cycle (with jitter mask).
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L; hex digits uppercased.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct PwmConfig {
    uint32_t periodTicks;
    float duty;
    uint32_t deadtimeTicks;
    uint32_t jitterMask;
};

static uint32_t pseudoJitter(uint32_t seed, uint32_t mask) {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed & mask;
}

int main() {
    const PwmConfig cfg{
        20000U,     // periodTicks (compliant)
        0.50F,      // duty (compliant)
        100U,       // deadtimeTicks (compliant)
        0X1FU       // jitterMask (compliant)
    };

    uint32_t prngSeed = 123U; // compliant
    const float minDuty = 0.05F; // compliant
    const float maxDuty = 0.95F; // compliant

    uint32_t j = pseudoJitter(prngSeed, cfg.jitterMask);
    float jitter = static_cast<float>(j) / 1024.0F; // compliant
    float duty = std::clamp(cfg.duty + jitter * 0.001F, minDuty, maxDuty); // compliant

    uint32_t cmp = static_cast<uint32_t>(duty * static_cast<float>(cfg.periodTicks));
    cmp = std::max(cmp, cfg.deadtimeTicks);
    cmp = std::min(cmp, cfg.periodTicks - cfg.deadtimeTicks);

    const long writeBudgetNS = 5000L; // compliant
    (void)writeBudgetNS;

    std::cout << "PWM config:\n";
    std::cout << "  periodTicks=" << cfg.periodTicks
              << " duty=" << std::fixed << std::setprecision(3) << cfg.duty
              << " deadtime=" << cfg.deadtimeTicks
              << " jitterMask=0x" << std::hex << cfg.jitterMask << std::dec << "\n";
    std::cout << "Computed compare=" << cmp << " (duty_eff=" << duty << ")\n";
    return 0;
}