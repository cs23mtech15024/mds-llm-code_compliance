// Context: Flight control roll angle estimator

// ------ Non-Compliant Program (053_nc.cpp)
// Seed 53 — Context: Flight control roll angle estimator
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 0.75f, 300u, 12l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_053 {
    constexpr float    rollRate    = 0.75f; // NC (rad/s nominal)
    constexpr unsigned iterations  = 300u;  // NC
    constexpr long     offsetCount = 12l;   // NC

    float estimateAngle(unsigned k) {
        // Toy estimate: integrate a sinusoidally varying rate
        float r = rollRate * (1.0f + 0.1f * std::sin(0.01f * static_cast<float>(k))); // NC
        return r * static_cast<float>(k) * 0.02f + static_cast<float>(offsetCount);    // NC
    }

    void run() {
        for (unsigned k = 0u; k < iterations; ++k) { // NC
            float angle = estimateAngle(k);
            if ((k % 50u) == 0u) { // NC
                std::cout << "[053] k=" << k << " angle="
                          << std::fixed << std::setprecision(3) << angle << "\n";
            }
        }
    }
}

int main() {
    app_053::run();
    return 0;
}
