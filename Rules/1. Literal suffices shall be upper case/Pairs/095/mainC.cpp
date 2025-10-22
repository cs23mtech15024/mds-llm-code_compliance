// Context: Autonomous rover lidar scan calibrator

// ------ Compliant Program (095_c.cpp)
// Context: Autonomous rover lidar scan calibrator
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_095 {
    // Seed literals (C): 0.45F, 128U, 60L
    constexpr float kScanGain = 0.45F;  // C
    constexpr unsigned kScans = 128U;   // C
    constexpr long kOffset = 60L;       // C

    struct Sample { float distance; float corrected; };

    float correct(float d) {
        float e = std::fabs(d - 5.0F); // C
        return d + kScanGain * e * 0.01F; // C
    }

    void run() {
        std::vector<Sample> s(kScans, {5.0F, 0.0F}); // C
        for (unsigned i = 0U; i < kScans; ++i) { // C
            float d = 5.0F + std::sin(0.05F * static_cast<float>(i)); // C
            s[i].distance = d;
            s[i].corrected = correct(d);
            if ((i % 32U) == 0U) {
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
