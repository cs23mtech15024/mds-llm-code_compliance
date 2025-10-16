// ------ Non-Compliant (Seed 025)
// Context: Networking — compute exponential retry backoff with jitter,
//          enforcing min/max timeout bounds.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', and 'l' suffixes; lowercase hex digits.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct BackoffCfg {
    float  baseSeconds;     // base backoff in seconds
    float  factor;          // exponential factor
    float  jitterFrac;      // fractional jitter (0..1)
    uint32_t maxAttempts;   // maximum attempts
    long   baseDelayMs;     // minimum clamp delay in ms
    uint32_t jitterMask;    // mask used by PRNG
};

static uint32_t jitterGen(uint32_t s) {
    // xorshift32
    s ^= s << 13;
    s ^= s >> 17;
    s ^= s << 5;
    return s;
}

int main() {
    const BackoffCfg cfg{
        0.50f,   // baseSeconds (non-compliant: 0.50F)
        2.0f,    // factor (non-compliant: 2.0F)
        0.10f,   // jitterFrac (non-compliant: 0.10F)
        5u,      // maxAttempts (non-compliant: 5U)
        250l,    // baseDelayMs (non-compliant: 250L)
        0x03ffu  // jitterMask (non-compliant: 0X03FFU)
    };

    uint32_t seed = 12345u; // non-compliant: 12345U
    const float minS = 0.05f; // non-compliant
    const float maxS = 10.0f; // non-compliant

    for (uint32_t attempt = 0u; attempt < cfg.maxAttempts; ++attempt) { // 0u non-compliant
        // exponential backoff
        float backoff = cfg.baseSeconds;
        for (uint32_t i = 0u; i < attempt; ++i) { // 0u non-compliant
            backoff *= cfg.factor;
        }

        // jitter in [0, jitterFrac]
        seed = jitterGen(seed);
        float j = static_cast<float>(seed & cfg.jitterMask) / 1024.0f; // non-compliant
        backoff += j * cfg.jitterFrac;

        // clamp
        backoff = std::clamp(backoff, minS, maxS);

        // convert to ms and respect minimum
        long delayMs = static_cast<long>(backoff * 1000.0f); // non-compliant
        delayMs = std::max(delayMs, cfg.baseDelayMs);

        std::cout << "Attempt " << attempt + 1u               // 1u non-compliant
                  << ": backoff=" << std::fixed << std::setprecision(3) << backoff
                  << "s, delay=" << delayMs << " ms\n";
    }

    return 0;
}