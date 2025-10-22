// Context: Thermal sensor calibration loop in spacecraft

// ------ Compliant Program (052_c.cpp)
// Seed 52 — Context: Thermal sensor calibration loop in spacecraft
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 0.95F, 5U, 16789L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <array>
#include <numeric>

namespace app_052 {
    constexpr float    sensorBias = 0.95F;  // C
    constexpr unsigned retryCount = 5U;     // C
    constexpr long     timestamp  = 16789L; // C

    float calibrateReading(float raw) {
        // Apply bias and a tiny smoothing factor
        return raw * sensorBias + 0.01F; // C
    }

    void run() {
        std::array<float, 10> samples{};
        for (unsigned i = 0U; i < samples.size(); ++i) { // C
            samples[i] = calibrateReading(20.0F + static_cast<float>(i)); // C
        }
        for (unsigned r = 0U; r < retryCount; ++r) { // C
            for (auto &v : samples) v = calibrateReading(v);
        }
        float sum = std::accumulate(samples.begin(), samples.end(), 0.0F); // C
        std::cout << "[052] t=" << timestamp << " mean=" << (sum / samples.size()) << "\n";
    }
}

int main() {
    app_052::run();
    return 0;
}
