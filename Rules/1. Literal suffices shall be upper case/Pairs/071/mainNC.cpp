// Context: High-speed rail braking force scheduler

// ------ Non-Compliant Program (071_nc.cpp)
// Context: High-speed rail braking force scheduler
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Violation: uses 0.62f, 64u, 120l (lowercase)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_071 {
    constexpr float    brakeGain = 0.62f; // NC
    constexpr unsigned samples   = 64u;   // NC
    constexpr long     ref       = 120l;  // NC

    float brakeForce(float v) {
        return brakeGain * std::sqrt(v) + static_cast<float>(ref);
    }

    void run() {
        std::vector<float> velocities(samples, 0.0f);
        for (unsigned i = 0u; i < samples; ++i) {
            velocities[i] = static_cast<float>(i) * 0.5f; // NC
        }
        for (unsigned i = 0u; i < samples; i += 8u) {
            float force = brakeForce(velocities[i]);
            std::cout << "[071] v=" << velocities[i] << " F=" << std::fixed << std::setprecision(2)
                      << force << " N\n";
        }
    }
}

int main(){ app_071::run(); return 0; }
