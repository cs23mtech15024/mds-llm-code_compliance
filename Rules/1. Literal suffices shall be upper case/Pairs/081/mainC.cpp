// Context: Space telescope mirror alignment algorithm

// ------ Compliant Program (081_c.cpp)
// Context: Space telescope mirror alignment algorithm
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

namespace app_081 {
    // Seed literals (C): 0.003F, 18U, 250L
    constexpr float kAlignRate = 0.003F;   // C
    constexpr unsigned kActuators = 18U;   // C
    constexpr long kSession = 250L;        // C

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
        std::vector<Mirror> mirrors(kActuators, {0.0F, 0.0F}); // C
        float reference = 1.0F; // C

        for (unsigned cycle = 0U; cycle < 500U; ++cycle) { // C
            for (auto& m : mirrors) {
                alignStep(m, reference);
            }

            if (cycle % 50U == 0U) {
                float avgError = 0.0F; // C
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
