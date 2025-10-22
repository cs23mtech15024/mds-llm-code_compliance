// Context: Smart factory conveyor motor calibrator

// ------ Compliant Program (099_c.cpp)
// Context: Smart factory conveyor motor calibrator
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_099 {
    // Seed literals (C): 0.75F, 4U, 200L
    constexpr float kMotorGain = 0.75F; // C
    constexpr unsigned kBelts = 4U;     // C
    constexpr long kOffset = 200L;      // C

    float calibrate(float rpm) {
        return rpm * kMotorGain + std::cos(rpm * 0.01F); // C
    }

    void run() {
        for (unsigned i = 0U; i < kBelts; ++i) { // C
            float rpm = 1000.0F + static_cast<float>(i) * 100.0F; // C
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
