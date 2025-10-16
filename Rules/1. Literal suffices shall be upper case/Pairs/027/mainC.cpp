// ------ Compliant (Seed 027)
// Context: Networking — schedule exponential backoff delays for HTTP retries.
//          Uses base delay, jitter, per-try cap, and an index mask to bucketize retries.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L; hex digits uppercased.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <random>
#include <algorithm>

struct BackoffCfg {
    float baseMs;
    float jitterFrac;
    unsigned maxRetries;
    unsigned capMs;
    long floorMs;
    std::uint32_t bucketMask;
};

static std::uint32_t clampDelay(float ms, unsigned cap, long floorVal) {
    const float clamped = std::max<float>(static_cast<float>(floorVal), std::min<float>(ms, static_cast<float>(cap)));
    return static_cast<std::uint32_t>(clamped);
}

int main() {
    const BackoffCfg cfg{
        250.0F,     // baseMs (compliant)
        0.15F,      // jitterFrac (compliant)
        5U,         // maxRetries (compliant)
        8000U,      // capMs (compliant)
        100L,       // floorMs (compliant)
        0X00FFU     // bucketMask (compliant)
    };

    std::mt19937 rng(0U); // compliant
    std::uniform_real_distribution<float> uni(-cfg.jitterFrac, cfg.jitterFrac);

    std::vector<std::uint32_t> delays;
    delays.reserve(cfg.maxRetries);

    float current = cfg.baseMs;
    for (unsigned attempt = 0U; attempt < cfg.maxRetries; ++attempt) { // compliant
        const float jitter = 1.0F + uni(rng); // compliant
        const float proposal = current * jitter;
        const auto ms = clampDelay(proposal, cfg.capMs, cfg.floorMs);
        delays.push_back(ms);
        current *= 2.0F; // compliant
    }

    std::cout << "Backoff plan (ms):";
    for (unsigned i = 0U; i < delays.size(); ++i) { // compliant
        const std::uint32_t bucket = (i & cfg.bucketMask);
        std::cout << " [" << std::setw(2) << i << "->" << std::setw(4) << delays[i]
                  << " bucket=" << bucket << "]";
    }
    std::cout << "\n";
    return 0;
}