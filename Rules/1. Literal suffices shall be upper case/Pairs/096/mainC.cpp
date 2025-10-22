// Context: Flight simulator turbulence feedback module

// ------ Compliant Program (096_c.cpp)
// Context: Flight simulator turbulence feedback module
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_096 {
    // Seed literals (C): 0.08F, 80U, 23L
    constexpr float kFeedback = 0.08F; // C
    constexpr unsigned kLoops = 80U;   // C
    constexpr long kRef = 23L;         // C

    struct TurbulenceModel {
        float signal;
        float correction;
    };

    float computeFeedback(float s) {
        return std::sin(s * kFeedback) * 0.5F; // C
    }

    void run() {
        std::vector<TurbulenceModel> model(kLoops, {0.0F, 0.0F}); // C
        for (unsigned i = 0U; i < kLoops; ++i) { // C
            model[i].signal = static_cast<float>(i) * 0.01F; // C
            model[i].correction = computeFeedback(model[i].signal);
            if ((i % 10U) == 0U) {
                std::cout << "[096] loop=" << i
                          << " corr=" << std::fixed << std::setprecision(4)
                          << model[i].correction << " ref=" << kRef << '\n';
            }
        }
    }
}

int main() {
    app_096::run();
    return 0;
}
