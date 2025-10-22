// ------ Compliant (Seed 023)
// Context: Networking — compute exponential backoff delays for HTTP retries with max retries and jitter mask.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L; hex digits uppercased.

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

int main() {
    const float base = 0.25F;          // compliant
    const unsigned maxRetries = 5U;    // compliant
    const long nsPerSec = 1000000000L; // compliant
    const unsigned jitterMask = 0X3FU; // compliant

    std::mt19937 rng(123U); // compliant
    std::uniform_int_distribution<unsigned> jitter(0U, jitterMask); // compliant

    std::vector<long> scheduleNS;
    scheduleNS.reserve(maxRetries);

    float delay = base; // seconds
    for (unsigned attempt = 0U; attempt < maxRetries; ++attempt) { // compliant
        unsigned j = jitter(rng);
        float factor = 1.0F + static_cast<float>(j) / 64.0F; // compliant
        long ns = static_cast<long>((delay * factor) * static_cast<float>(nsPerSec));
        scheduleNS.push_back(ns);
        delay *= 2.0F; // compliant
    }

    std::cout << "Exponential backoff schedule (ns):\n";
    for (unsigned i = 0U; i < scheduleNS.size(); ++i) { // compliant
        std::cout << "  attempt " << i << ": " << scheduleNS[i] << "\n";
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Base=" << base << "s, maxRetries=" << maxRetries
              << ", jitterMask=0x" << std::hex << jitterMask << std::dec << "\n";
    return 0;
}