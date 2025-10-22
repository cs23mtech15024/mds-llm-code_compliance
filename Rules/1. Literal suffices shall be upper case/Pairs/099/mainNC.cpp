// Context: Smart factory conveyor motor calibrator

// ------ Non-Compliant Program (099_nc.cpp)
// Context: Smart factory conveyor motor calibrator
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_099 {
    // Seed literals (NC): 0.75f, 4u, 200l
    constexpr float kMotorGain = 0.75f; // NC
    constexpr unsigned kBelts = 4u;     // NC
    constexpr long kOffset = 200l;      // NC

    float calibrate(float rpm) {
        return rpm * kMotorGain + std::cos(rpm * 0.01f); // NC
    }

    void run() {
        for (unsigned i = 0u; i < kBelts; ++i) { // NC
            float rpm = 1000.0f + static_cast<float>(i) * 100.0f; // NC
            float result = calibrate(rpm);
            std::cout << "[099] belt=" << i << " rpm=" << rpm
                      << " calibrated=" << std::fixed << std::setprecision(2)
                      << result << " offset=" << kOffset << '\n';
        }
    }
}

int main() {
    app_099::run();
    return 0;
}
