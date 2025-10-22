// Context: Hydraulic pressure feedback controller

// ------ Compliant Program (054_c.cpp)
// Seed 54 — Context: Hydraulic pressure feedback controller
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 2.5F, 200U, 10L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <vector>

namespace app_054 {
    constexpr float    feedbackGain = 2.5F;  // C
    constexpr unsigned cycleCount   = 200U;  // C
    constexpr long     startTick    = 10L;   // C

    float loopStep(float pressure, float target) {
        float err = target - pressure;
        return pressure + feedbackGain * err * 0.01F; // C
    }

    void run() {
        float target = 250.0F + static_cast<float>(startTick); // C
        float p = 200.0F;                                      // C
        for (unsigned k = 0U; k < cycleCount; ++k) { // C
            p = loopStep(p, target);
            if ((k % 40U) == 0U) { // C
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
