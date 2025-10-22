// Context: Submarine sonar signal amplifier tuner

// ------ Compliant Program (098_c.cpp)
// Context: Submarine sonar signal amplifier tuner
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace app_098 {
    // Seed literals (C): 4.4F, 20U, 15L
    constexpr float kAmp = 4.4F; // C
    constexpr unsigned kFreq = 20U; // C
    constexpr long kTime = 15L; // C

    float amplify(float input) {
        return std::sin(input) * kAmp + 0.2F; // C
    }

    void run() {
        std::vector<float> signals(kFreq);
        for (unsigned i = 0U; i < kFreq; ++i) { // C
            float in = static_cast<float>(i) * 0.1F; // C
            signals[i] = amplify(in);
            if ((i % 5U) == 0U) {
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
