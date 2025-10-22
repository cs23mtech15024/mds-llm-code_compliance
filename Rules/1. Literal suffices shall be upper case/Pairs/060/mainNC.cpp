// Context: Aircraft flap position scheduler

// ------ Non-Compliant Program (060_nc.cpp)
// Seed 60 — Context: Aircraft flap position scheduler
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 9.81f, 50u, 2024l, 0x1234u (lowercase suffixes / hex)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_060 {
    constexpr float    flapGain = 9.81f;   // NC
    constexpr unsigned delay    = 50u;     // NC (ms)
    constexpr long     ref      = 2024l;   // NC
    constexpr unsigned mask     = 0x1234u; // NC

    float schedule(float speed, unsigned k) {
        float base = flapGain * 0.1f * std::log(1.0f + speed); // NC
        float step = (static_cast<unsigned>(k) & mask) == 0u ? 2.0f : 0.5f; // NC
        return base + step + static_cast<float>(ref) * 0.001f; // NC
    }

    void run() {
        for (unsigned k = 0u; k < 500u; ++k) { // NC
            float spd = 60.0f + 0.2f * static_cast<float>(k); // NC
            float cmd = schedule(spd, k);
            if (k % delay == 0u) { // NC
                std::cout << "[060] k=" << k << " flap_cmd=" << std::fixed
                          << std::setprecision(3) << cmd << "\n";
            }
        }
    }
}

int main() {
    app_060::run();
    return 0;
}
