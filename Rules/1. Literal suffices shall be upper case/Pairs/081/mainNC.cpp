// Context: Space telescope mirror alignment algorithm

// ------ Non-Compliant Program (081_nc.cpp)
// Context: Space telescope mirror alignment algorithm
// Rule: MISRA C++ 2-13-4 — lowercase suffixes intentionally (NC)

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

namespace app_081 {
    // Seed literals (NC): 0.003f, 18u, 250l
    constexpr float kAlignRate = 0.003f;   // NC
    constexpr unsigned kActuators = 18u;   // NC
    constexpr long kSession = 250l;        // NC

    struct Mirror {
        float position;
        float error;
    };

    void alignStep(Mirror& m, float ref) {
        float correction = (ref - m.position) * kAlignRate;
        m.position += correction;
        m.error = ref - m.position;
    }

    void run() {
        std::vector<Mirror> mirrors(kActuators, {0.0f, 0.0f}); // NC
        float reference = 1.0f; // NC

        for (unsigned cycle = 0u; cycle < 500u; ++cycle) { // NC
            for (auto& m : mirrors) {
                alignStep(m, reference);
            }

            if (cycle % 50u == 0u) {
                float avgError = 0.0f; // NC
                for (const auto& m : mirrors) { avgError += m.error; }
                avgError /= static_cast<float>(mirrors.size());
                std::cout << "[081] cycle=" << std::setw(3) << cycle
                          << " avg_error=" << std::fixed << std::setprecision(6)
                          << avgError << '\n';
            }
        }
        std::cout << "SESSION=" << kSession << '\n';
    }
}

int main() {
    app_081::run();
    return 0;
}
