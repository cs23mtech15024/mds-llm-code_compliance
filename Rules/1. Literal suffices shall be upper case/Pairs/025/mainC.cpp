// ------ Compliant (Seed 025)
// Context: Networking — compute exponential retry backoff with jitter,
//          enforcing min/max timeout bounds.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L; hex digits uppercased.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct BackoffCfg {
    float  baseSeconds;
    float  factor;
    float  jitterFrac;
    uint32_t maxAttempts;
    long   baseDelayMs;
    uint32_t jitterMask;
};

static uint32_t jitterGen(uint32_t s) {
    s ^= s << 13;
    s ^= s >> 17;
    s ^= s << 5;
    return s;
}

int main() {
    const BackoffCfg cfg{
        0.50F,   // baseSeconds (compliant)
        2.0F,    // factor (compliant)
        0.10F,   // jitterFrac (compliant)
        5U,      // maxAttempts (compliant)
        250L,    // baseDelayMs (compliant)
        0X03FFU  // jitterMask (compliant)
    };

    uint32_t seed = 12345U; // compliant
    const float minS = 0.05F; // compliant
    const float maxS = 10.0F; // compliant

    for (uint32_t attempt = 0U; attempt < cfg.maxAttempts; ++attempt) { // compliant
        float backoff = cfg.baseSeconds;
        for (uint32_t i = 0U; i < attempt; ++i) { // compliant
            backoff *= cfg.factor;
        }

        seed = jitterGen(seed);
        float j = static_cast<float>(seed & cfg.jitterMask) / 1024.0F; // compliant
        backoff += j * cfg.jitterFrac;

        backoff = std::min(backoff, minS, maxS);

        long delayMs = static_cast<long>(backoff * 1000.0F); // compliant
        delayMs = std::max(delayMs, cfg.baseDelayMs);

        std::cout << "Attempt " << attempt + 1U
                  << ": backoff=" << std::fixed << std::setprecision(3) << backoff
                  << "s, delay=" << delayMs << " ms\n";
    }

    return 0;
}