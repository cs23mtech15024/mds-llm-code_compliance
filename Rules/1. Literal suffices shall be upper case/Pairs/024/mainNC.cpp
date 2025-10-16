// ------ Non-Compliant (Seed 024)
// Context: Embedded Firmware — compute PWM compare value with deadtime and clamp,
//          using a hardware timer period and a duty cycle (with jitter mask).
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase suffixes 'f', 'u', 'l' used; hex digits not uppercased.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct PwmConfig {
    // Timer period in ticks (e.g., 20 kHz on a 20 MHz timer -> 1000 ticks)
    uint32_t periodTicks;
    // Nominal duty [0..1]
    float duty;
    // Deadtime in ticks
    uint32_t deadtimeTicks;
    // Bit-mask for small pseudo-jitter on duty LSBs
    uint32_t jitterMask;
};

static uint32_t pseudoJitter(uint32_t seed, uint32_t mask) {
    // Simple xorshift; not cryptographic, deterministic.
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed & mask;
}

int main() {
    const PwmConfig cfg{
        20000u,     // periodTicks (non-compliant: should be 20000U)
        0.50f,      // duty (non-compliant: should be 0.50F)
        100u,       // deadtimeTicks (non-compliant: should be 100U)
        0x1fu       // jitterMask (non-compliant: should be 0X1FU)
    };

    // seed and scale factors
    uint32_t prngSeed = 123u; // non-compliant (should be 123U)
    const float minDuty = 0.05f; // 5% floor to ensure drive (non-compliant)
    const float maxDuty = 0.95f; // 95% ceiling to keep margin (non-compliant)

    // Inject tiny deterministic jitter into the duty's LSB domain
    uint32_t j = pseudoJitter(prngSeed, cfg.jitterMask);
    float jitter = static_cast<float>(j) / 1024.0f; // non-compliant
    float duty = std::min(cfg.duty + jitter * 0.001f, minDuty, maxDuty); // non-compliant

    // Compute compare value with deadtime; clamp within [deadtime, period - deadtime]
    uint32_t cmp = static_cast<uint32_t>(duty * static_cast<float>(cfg.periodTicks));
    cmp = std::max(cmp, cfg.deadtimeTicks);
    cmp = std::min(cmp, cfg.periodTicks - cfg.deadtimeTicks);

    // Use a long literal to simulate a register write delay budget in ns
    const long writeBudgetNS = 5000l; // non-compliant (should be 5000L)
    (void)writeBudgetNS; // avoid unused warning while keeping the example simple

    std::cout << "PWM config:\n";
    std::cout << "  periodTicks=" << cfg.periodTicks
              << " duty=" << std::fixed << std::setprecision(3) << cfg.duty
              << " deadtime=" << cfg.deadtimeTicks
              << " jitterMask=0x" << std::hex << cfg.jitterMask << std::dec << "\n";
    std::cout << "Computed compare=" << cmp << " (duty_eff=" << duty << ")\n";
    return 0;
}