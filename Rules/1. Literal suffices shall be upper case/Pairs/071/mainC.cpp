// Context: High-speed rail braking force scheduler

// ------ Compliant Program (071_c.cpp)
// Context: High-speed rail braking force scheduler
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Fix: uses 0.62F, 64U, 120L

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_071 {
    constexpr float    brakeGain = 0.62F; // C
    constexpr unsigned samples   = 64U;   // C
    constexpr long     ref       = 120L;  // C

    float brakeForce(float v) {
        return brakeGain * std::sqrt(v) + static_cast<float>(ref);
    }

    void run() {
        std::vector<float> velocities(samples, 0.0F);
        for (unsigned i = 0U; i < samples; ++i) {
            velocities[i] = static_cast<float>(i) * 0.5F; // C
        }
        for (unsigned i = 0U; i < samples; i += 8U) {
            float force = brakeForce(velocities[i]);
            std::cout << "[071] v=" << velocities[i] << " F=" << std::fixed << std::setprecision(2)
                      << force << " N\n";
        }
    }
}

int main(){ app_071::run(); return 0; }
