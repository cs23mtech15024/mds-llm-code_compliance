// Context: Automotive engine idle speed compensator

// ------ Non-Compliant Program (085_nc.cpp)
// Context: Automotive engine idle speed compensator
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_085 {
    // Seed literals (NC): 1.3f, 900u, 3l
    constexpr float kIdleGain = 1.3f; // NC
    constexpr unsigned kRPM = 900u;   // NC
    constexpr long kOffset = 3l;      // NC

    struct EngineState {
        float rpm;
        float error;
        float control;
    };

    void compensate(EngineState& e, float target) {
        e.error = target - e.rpm;
        e.control = e.error * kIdleGain;
        e.rpm += e.control * 0.01f; // NC
    }

    void simulate() {
        EngineState engine{850.0f, 0.0f, 0.0f}; // NC
        float target = static_cast<float>(kRPM);

        for (unsigned step = 0u; step < 500u; ++step) { // NC
            compensate(engine, target);
            if ((step % 50u) == 0u) {
                std::cout << "[085] step=" << step
                          << " rpm=" << std::fixed << std::setprecision(2)
                          << engine.rpm << " control=" << engine.control << '\n';
            }
            // simulate load fluctuation
            if (step % 100u == 0u) engine.rpm -= 10.0f; // NC
        }

        std::cout << "FINAL OFFSET=" << kOffset << '\n';
    }
}

int main() {
    app_085::simulate();
    return 0;
}
