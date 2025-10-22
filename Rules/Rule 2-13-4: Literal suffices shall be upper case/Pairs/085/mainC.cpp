// Context: Automotive engine idle speed compensator

// ------ Compliant Program (085_c.cpp)
// Context: Automotive engine idle speed compensator
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_085 {
    // Seed literals (C): 1.3F, 900U, 3L
    constexpr float kIdleGain = 1.3F; // C
    constexpr unsigned kRPM = 900U;   // C
    constexpr long kOffset = 3L;      // C

    struct EngineState {
        float rpm;
        float error;
        float control;
    };

    void compensate(EngineState& e, float target) {
        e.error = target - e.rpm;
        e.control = e.error * kIdleGain;
        e.rpm += e.control * 0.01F; // C
    }

    void simulate() {
        EngineState engine{850.0F, 0.0F, 0.0F}; // C
        float target = static_cast<float>(kRPM);

        for (unsigned step = 0U; step < 500U; ++step) { // C
            compensate(engine, target);
            if ((step % 50U) == 0U) {
                std::cout << "[085] step=" << step
                          << " rpm=" << std::fixed << std::setprecision(2)
                          << engine.rpm << " control=" << engine.control << '\n';
            }
            // simulate load fluctuation
            if (step % 100U == 0U) engine.rpm -= 10.0F; // C
        }

        std::cout << "FINAL OFFSET=" << kOffset << '\n';
    }
}

int main() {
    app_085::simulate();
    return 0;
}
