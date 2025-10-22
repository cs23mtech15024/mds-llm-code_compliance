// Context: Marine autopilot heading correction loop

// ------ Non-Compliant Program (059_nc.cpp)
// Seed 59 — Context: Marine autopilot heading correction loop
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 3.14f, 50u, 7l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_059 {
    constexpr float    headingError = 3.14f; // NC (rad)
    constexpr unsigned rate         = 50u;   // NC (Hz)
    constexpr long     correction   = 7l;    // NC (ticks)

    float correctionStep(unsigned k) {
        float alpha = 0.02f * static_cast<float>(k); // NC
        return std::sin(headingError + alpha) * 5.0f + static_cast<float>(correction); // NC
    }

    void run() {
        float sum = 0.0f; // NC
        for (unsigned k = 0u; k < 200u; ++k) { // NC
            sum += correctionStep(k);
            if ((k % rate) == 0u) { // NC
                std::cout << "[059] k=" << k << " cmd=" << std::fixed
                          << std::setprecision(3) << sum << "\n";
            }
        }
    }
}

int main() {
    app_059::run();
    return 0;
}
