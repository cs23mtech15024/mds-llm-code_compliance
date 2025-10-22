// Context: Aircraft flap position scheduler

// ------ Compliant Program (060_c.cpp)
// Seed 60 — Context: Aircraft flap position scheduler
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 9.81F, 50U, 2024L, 0X1234U (uppercase suffixes / hex)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_060 {
    constexpr float    flapGain = 9.81F;    // C
    constexpr unsigned delay    = 50U;      // C (ms)
    constexpr long     ref      = 2024L;    // C
    constexpr unsigned mask     = 0X1234U;  // C

    float schedule(float speed, unsigned k) {
        float base = flapGain * 0.1F * std::log(1.0F + speed); // C
        float step = (static_cast<unsigned>(k) & mask) == 0U ? 2.0F : 0.5F; // C
        return base + step + static_cast<float>(ref) * 0.001F; // C
    }

    void run() {
        for (unsigned k = 0U; k < 500U; ++k) { // C
            float spd = 60.0F + 0.2F * static_cast<float>(k); // C
            float cmd = schedule(spd, k);
            if (k % delay == 0U) { // C
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
