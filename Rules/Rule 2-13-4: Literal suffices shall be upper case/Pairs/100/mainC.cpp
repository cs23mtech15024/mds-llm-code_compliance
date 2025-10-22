// Context: Path planner smoothing

// ------ Compliant Program (100_c.cpp)
// Context: Path planner smoothing
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_100 {
    // Seed literals (C): 9.81F, 50U, 2024L, 0X1234U
    constexpr float kAccel = 9.81F;   // C
    constexpr unsigned kSteps = 50U;  // C
    constexpr long kTime = 2024L;     // C
    constexpr unsigned kMask = 0X1234U; // C

    float smooth(float x) {
        return std::sin(x * kAccel * 0.01F); // C
    }

    void run() {
        std::vector<float> path(kSteps);
        for (unsigned i = 0U; i < kSteps; ++i) { // C
            path[i] = smooth(static_cast<float>(i));
            if ((i & kMask) == 0U) {
                std::cout << "[100] step=" << i << " val=" << std::fixed << std::setprecision(4)
                          << path[i] << " time=" << kTime << '\n';
            }
        }
    }
}

int main() {
    app_100::run();
    return 0;
}
