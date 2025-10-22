// Context: Hydraulic pressure feedback controller

// ------ Non-Compliant Program (054_nc.cpp)
// Seed 54 — Context: Hydraulic pressure feedback controller
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 2.5f, 200u, 10l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <vector>

namespace app_054 {
    constexpr float    feedbackGain = 2.5f;  // NC
    constexpr unsigned cycleCount   = 200u;  // NC
    constexpr long     startTick    = 10l;   // NC

    float loopStep(float pressure, float target) {
        float err = target - pressure;
        return pressure + feedbackGain * err * 0.01f; // NC
    }

    void run() {
        float target = 250.0f + static_cast<float>(startTick); // NC
        float p = 200.0f;                                      // NC
        for (unsigned k = 0u; k < cycleCount; ++k) { // NC
            p = loopStep(p, target);
            if ((k % 40u) == 0u) { // NC
                std::cout << "[054] k=" << k << " p=" << std::fixed
                          << std::setprecision(1) << p << "\n";
            }
        }
    }
}

int main() {
    app_054::run();
    return 0;
}
