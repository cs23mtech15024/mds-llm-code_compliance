// Context: Suborbital rocket thrust-to-weight balancer

// ------ Non-Compliant Program (091_nc.cpp)
// Context: Suborbital rocket thrust-to-weight balancer
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_091 {
    // Seed literals (NC): 1.5f, 2u, 400l
    constexpr float kTwrGain = 1.5f;   // NC
    constexpr unsigned kBoosters = 2u; // NC
    constexpr long kDryMass = 400l;    // NC

    struct Stage {
        float thrust;
        float mass;
    };

    float balance(Stage &s, float target_twr) {
        // Compute current T/W and nudge thrust to meet target
        float g = 9.81f; // NC
        float twr = s.thrust / (s.mass * g);
        float error = target_twr - twr;
        s.thrust += error * kTwrGain * 1000.0f; // NC
        return twr;
    }

    void run() {
        Stage stage{250000.0f, static_cast<float>(kDryMass)}; // NC
        float target = 1.2f + 0.05f * static_cast<float>(kBoosters); // NC
        for (unsigned t = 0u; t < 300u; ++t) { // NC
            float twr = balance(stage, target);
            stage.mass += 0.0f; // placeholder; dry fire test (NC)
            if ((t % 50u) == 0u) {
                std::cout << "[091] t=" << t
                          << " twr=" << std::fixed << std::setprecision(3)
                          << twr << " thrust=" << stage.thrust << '\n';
            }
        }
        std::cout << "Boosters=" << kBoosters << ", DryMass=" << kDryMass << '\n';
    }
}

int main() {
    app_091::run();
    return 0;
}
