// Context: Thermal sensor calibration loop in spacecraft

// ------ Non-Compliant Program (052_nc.cpp)
// Seed 52 — Context: Thermal sensor calibration loop in spacecraft
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 0.95f, 5u, 16789l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <array>
#include <numeric>

namespace app_052 {
    constexpr float    sensorBias = 0.95f;  // NC
    constexpr unsigned retryCount = 5u;     // NC
    constexpr long     timestamp  = 16789l; // NC

    float calibrateReading(float raw) {
        // Apply bias and a tiny smoothing factor
        return raw * sensorBias + 0.01f; // NC
    }

    void run() {
        std::array<float, 10> samples{};
        for (unsigned i = 0u; i < samples.size(); ++i) { // NC
            samples[i] = calibrateReading(20.0f + static_cast<float>(i)); // NC
        }
        for (unsigned r = 0u; r < retryCount; ++r) { // NC
            for (auto &v : samples) v = calibrateReading(v);
        }
        float sum = std::accumulate(samples.begin(), samples.end(), 0.0f); // NC
        std::cout << "[052] t=" << timestamp << " mean=" << (sum / samples.size()) << "\n";
    }
}

int main() {
    app_052::run();
    return 0;
}
