// Context: Flight simulator turbulence feedback module

// ------ Non-Compliant Program (096_nc.cpp)
// Context: Flight simulator turbulence feedback module
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_096 {
    // Seed literals (NC): 0.08f, 80u, 23l
    constexpr float kFeedback = 0.08f; // NC
    constexpr unsigned kLoops = 80u;   // NC
    constexpr long kRef = 23l;         // NC

    struct TurbulenceModel {
        float signal;
        float correction;
    };

    float computeFeedback(float s) {
        return std::sin(s * kFeedback) * 0.5f; // NC
    }

    void run() {
        std::vector<TurbulenceModel> model(kLoops, {0.0f, 0.0f}); // NC
        for (unsigned i = 0u; i < kLoops; ++i) { // NC
            model[i].signal = static_cast<float>(i) * 0.01f; // NC
            model[i].correction = computeFeedback(model[i].signal);
            if ((i % 10u) == 0u) {
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
