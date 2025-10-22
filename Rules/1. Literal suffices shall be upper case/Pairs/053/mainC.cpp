// Context: Flight control roll angle estimator

// ------ Compliant Program (053_c.cpp)
// Seed 53 — Context: Flight control roll angle estimator
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 0.75F, 300U, 12L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_053 {
    constexpr float    rollRate    = 0.75F; // C (rad/s nominal)
    constexpr unsigned iterations  = 300U;  // C
    constexpr long     offsetCount = 12L;   // C

    float estimateAngle(unsigned k) {
        // Toy estimate: integrate a sinusoidally varying rate
        float r = rollRate * (1.0F + 0.1F * std::sin(0.01F * static_cast<float>(k))); // C
        return r * static_cast<float>(k) * 0.02F + static_cast<float>(offsetCount);    // C
    }

    void run() {
        for (unsigned k = 0U; k < iterations; ++k) { // C
            float angle = estimateAngle(k);
            if ((k % 50U) == 0U) { // C
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
