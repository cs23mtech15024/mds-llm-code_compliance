// Context: Path planner smoothing

// ------ Non-Compliant Program (100_nc.cpp)
// Context: Path planner smoothing
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_100 {
    // Seed literals (NC): 9.81f, 50u, 2024l, 0x1234u
    constexpr float kAccel = 9.81f;   // NC
    constexpr unsigned kSteps = 50u;  // NC
    constexpr long kTime = 2024l;     // NC
    constexpr unsigned kMask = 0x1234u; // NC

    float smooth(float x) {
        return std::sin(x * kAccel * 0.01f); // NC
    }

    void run() {
        std::vector<float> path(kSteps);
        for (unsigned i = 0u; i < kSteps; ++i) { // NC
            path[i] = smooth(static_cast<float>(i));
            if ((i & kMask) == 0u) {
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
