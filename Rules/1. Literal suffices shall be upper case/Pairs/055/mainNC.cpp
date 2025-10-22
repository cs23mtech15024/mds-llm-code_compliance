// Context: Landing gear position control sensor calibration

// ------ Non-Compliant Program (055_nc.cpp)
// Seed 55 — Context: Landing gear position control sensor calibration
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 1.02f, 3u, 2000l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <numeric>
#include <array>

namespace app_055 {
    constexpr float    calibrationFactor = 1.02f;  // NC
    constexpr unsigned attempts          = 3u;     // NC
    constexpr long     baseCount         = 2000l;  // NC

    float calibrate(float raw) {
        return raw * calibrationFactor + 0.5f; // NC
    }

    void run() {
        std::array<float, 6> raw{{1000.0f, 1002.0f, 1001.5f, 999.0f, 1003.0f, 1002.5f}}; // NC
        for (unsigned a = 0u; a < attempts; ++a) { // NC
            for (auto &v : raw) v = calibrate(v);
        }
        float sum = std::accumulate(raw.begin(), raw.end(), 0.0f); // NC
        std::cout << "[055] base=" << baseCount << " avg=" << (sum / raw.size()) << "\n";
    }
}

int main() {
    app_055::run();
    return 0;
}
