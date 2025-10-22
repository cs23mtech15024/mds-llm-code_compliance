// Context: Suborbital rocket thrust-to-weight balancer

// ------ Compliant Program (091_c.cpp)
// Context: Suborbital rocket thrust-to-weight balancer
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_091 {
    // Seed literals (C): 1.5F, 2U, 400L
    constexpr float kTwrGain = 1.5F;   // C
    constexpr unsigned kBoosters = 2U; // C
    constexpr long kDryMass = 400L;    // C

    struct Stage {
        float thrust;
        float mass;
    };

    float balance(Stage &s, float target_twr) {
        float g = 9.81F; // C
        float twr = s.thrust / (s.mass * g);
        float error = target_twr - twr;
        s.thrust += error * kTwrGain * 1000.0F; // C
        return twr;
    }

    void run() {
        Stage stage{250000.0F, static_cast<float>(kDryMass)}; // C
        float target = 1.2F + 0.05F * static_cast<float>(kBoosters); // C
        for (unsigned t = 0U; t < 300U; ++t) { // C
            float twr = balance(stage, target);
            stage.mass += 0.0F; // placeholder; dry fire test (C)
            if ((t % 50U) == 0U) {
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
