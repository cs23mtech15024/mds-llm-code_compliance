// Context: Marine autopilot heading correction loop

// ------ Compliant Program (059_c.cpp)
// Seed 59 — Context: Marine autopilot heading correction loop
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 3.14F, 50U, 7L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_059 {
    constexpr float    headingError = 3.14F; // C (rad)
    constexpr unsigned rate         = 50U;   // C (Hz)
    constexpr long     correction   = 7L;    // C (ticks)

    float correctionStep(unsigned k) {
        float alpha = 0.02F * static_cast<float>(k); // C
        return std::sin(headingError + alpha) * 5.0F + static_cast<float>(correction); // C
    }

    void run() {
        float sum = 0.0F; // C
        for (unsigned k = 0U; k < 200U; ++k) { // C
            sum += correctionStep(k);
            if ((k % rate) == 0U) { // C
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
