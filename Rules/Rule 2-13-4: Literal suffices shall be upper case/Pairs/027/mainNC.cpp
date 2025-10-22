// ------ Non-Compliant (Seed 027)
// Context: Networking — schedule exponential backoff delays for HTTP retries.
//          Uses base delay, jitter, per-try cap, and an index mask to bucketize retries.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in hex literal.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <random>
#include <algorithm>

struct BackoffCfg {
    float baseMs;         // base delay in milliseconds
    float jitterFrac;     // jitter fraction [0,1]
    unsigned maxRetries;  // maximum retry attempts
    unsigned capMs;       // per-attempt cap in milliseconds
    long floorMs;         // minimum delay floor in milliseconds
    std::uint32_t bucketMask; // for bucketing retry indices
};

static std::uint32_t clampDelay(float ms, unsigned cap, long floorVal) {
    const float clamped = std::max<float>(static_cast<float>(floorVal), std::min<float>(ms, static_cast<float>(cap)));
    return static_cast<std::uint32_t>(clamped);
}

int main() {
    const BackoffCfg cfg{
        250.0f,     // baseMs (non-compliant)
        0.15f,      // jitterFrac (non-compliant)
        5u,         // maxRetries (non-compliant)
        8000u,      // capMs (non-compliant)
        100l,       // floorMs (non-compliant)
        0x00ffu     // bucketMask (non-compliant)
    };

    std::mt19937 rng(0u); // non-compliant
    std::uniform_real_distribution<float> uni(-cfg.jitterFrac, cfg.jitterFrac);

    std::vector<std::uint32_t> delays;
    delays.reserve(cfg.maxRetries);

    float current = cfg.baseMs;
    for (unsigned attempt = 0u; attempt < cfg.maxRetries; ++attempt) { // 0u non-compliant
        const float jitter = 1.0f + uni(rng); // non-compliant
        const float proposal = current * jitter;
        const auto ms = clampDelay(proposal, cfg.capMs, cfg.floorMs);
        delays.push_back(ms);
        current *= 2.0f; // non-compliant
    }

    std::cout << "Backoff plan (ms):";
    for (unsigned i = 0u; i < delays.size(); ++i) { // 0u non-compliant
        const std::uint32_t bucket = (i & cfg.bucketMask);
        std::cout << " [" << std::setw(2) << i << "->" << std::setw(4) << delays[i]
                  << " bucket=" << bucket << "]";
    }
    std::cout << "\n";
    return 0;
}