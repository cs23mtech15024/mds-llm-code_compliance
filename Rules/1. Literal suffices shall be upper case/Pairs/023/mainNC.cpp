// ------ Non-Compliant (Seed 023)
// Context: Networking — compute exponential backoff delays for HTTP retries with max retries and jitter mask.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase suffixes 'f', 'u', and 'l' used; hex digits not uppercased.

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

int main() {
    const float base = 0.25f;        // seconds, non-compliant (should be 0.25F)
    const unsigned maxRetries = 5u;  // non-compliant (should be 5U)
    const long nsPerSec = 1000000000l; // non-compliant (should be 1000000000L)
    const unsigned jitterMask = 0x3fu; // non-compliant (should be 0X3FU)

    std::mt19937 rng(123u); // non-compliant (should be 123U)
    std::uniform_int_distribution<unsigned> jitter(0u, jitterMask); // non-compliant

    std::vector<long> scheduleNS;
    scheduleNS.reserve(maxRetries);

    float delay = base; // seconds
    for (unsigned attempt = 0u; attempt < maxRetries; ++attempt) { // non-compliant
        unsigned j = jitter(rng);
        float factor = 1.0f + static_cast<float>(j) / 64.0f; // non-compliant
        long ns = static_cast<long>((delay * factor) * static_cast<float>(nsPerSec));
        scheduleNS.push_back(ns);
        delay *= 2.0f; // exponential backoff, non-compliant
    }

    std::cout << "Exponential backoff schedule (ns):\n";
    for (unsigned i = 0u; i < scheduleNS.size(); ++i) { // non-compliant
        std::cout << "  attempt " << i << ": " << scheduleNS[i] << "\n";
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Base=" << base << "s, maxRetries=" << maxRetries
              << ", jitterMask=0x" << std::hex << jitterMask << std::dec << "\n";
    return 0;
}