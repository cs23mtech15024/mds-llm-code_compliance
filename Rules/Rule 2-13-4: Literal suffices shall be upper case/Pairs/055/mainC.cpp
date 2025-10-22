// Context: Landing gear position control sensor calibration

// ------ Compliant Program (055_c.cpp)
// Seed 55 — Context: Landing gear position control sensor calibration
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 1.02F, 3U, 2000L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <numeric>
#include <array>

namespace app_055 {
    constexpr float    calibrationFactor = 1.02F;  // C
    constexpr unsigned attempts          = 3U;     // C
    constexpr long     baseCount         = 2000L;  // C

    float calibrate(float raw) {
        return raw * calibrationFactor + 0.5F; // C
    }

    void run() {
        std::array<float, 6> raw{{1000.0F, 1002.0F, 1001.5F, 999.0F, 1003.0F, 1002.5F}}; // C
        for (unsigned a = 0U; a < attempts; ++a) { // C
            for (auto &v : raw) v = calibrate(v);
        }
        float sum = std::accumulate(raw.begin(), raw.end(), 0.0F); // C
        std::cout << "[055] base=" << baseCount << " avg=" << (sum / raw.size()) << "\n";
    }
}

int main() {
    app_055::run();
    return 0;
}
