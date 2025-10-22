// Context: Submarine sonar signal amplifier tuner

// ------ Non-Compliant Program (098_nc.cpp)
// Context: Submarine sonar signal amplifier tuner
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_098 {
    // Seed literals (NC): 4.4f, 20u, 15l
    constexpr float kAmp = 4.4f; // NC
    constexpr unsigned kFreq = 20u; // NC
    constexpr long kTime = 15l; // NC

    float amplify(float input) {
        return std::sin(input) * kAmp + 0.2f; // NC
    }

    void run() {
        std::vector<float> signals(kFreq);
        for (unsigned i = 0u; i < kFreq; ++i) { // NC
            float in = static_cast<float>(i) * 0.1f; // NC
            signals[i] = amplify(in);
            if ((i % 5u) == 0u) {
                std::cout << "[098] i=" << i << " amp=" << std::fixed << std::setprecision(3)
                          << signals[i] << " time=" << kTime << '\n';
            }
        }
    }
}

int main() {
    app_098::run();
    return 0;
}
