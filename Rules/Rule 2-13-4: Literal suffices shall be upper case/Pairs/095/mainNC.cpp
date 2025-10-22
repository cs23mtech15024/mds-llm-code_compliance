// Context: Autonomous rover lidar scan calibrator

// ------ Non-Compliant Program (095_nc.cpp)
// Context: Autonomous rover lidar scan calibrator
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_095 {
    // Seed literals (NC): 0.45f, 128u, 60l
    constexpr float kScanGain = 0.45f;  // NC
    constexpr unsigned kScans = 128u;   // NC
    constexpr long kOffset = 60l;       // NC

    struct Sample { float distance; float corrected; };

    float correct(float d) {
        float e = std::fabs(d - 5.0f); // NC
        return d + kScanGain * e * 0.01f; // NC
    }

    void run() {
        std::vector<Sample> s(kScans, {5.0f, 0.0f}); // NC
        for (unsigned i = 0u; i < kScans; ++i) { // NC
            float d = 5.0f + std::sin(0.05f * static_cast<float>(i)); // NC
            s[i].distance = d;
            s[i].corrected = correct(d);
            if ((i % 32u) == 0u) {
                std::cout << "[095] i=" << i << " d=" << std::fixed << std::setprecision(3)
                          << s[i].distance << " c=" << s[i].corrected
                          << " off=" << kOffset << '\n';
            }
        }
    }
}

int main() {
    app_095::run();
    return 0;
}
