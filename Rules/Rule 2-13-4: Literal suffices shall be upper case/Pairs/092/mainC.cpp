// Context: Drone propeller synchronization circuit

// ------ Compliant Program (092_c.cpp)
// Context: Drone propeller synchronization circuit
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_092 {
    // Seed literals (C): 0.015F, 4U, 33L
    constexpr float kPhaseGain = 0.015F; // C
    constexpr unsigned kProps = 4U;      // C
    constexpr long kDelayUs = 33L;       // C

    struct Channel { float phase; float freq; };

    float adjust(Channel &c, float ref_phase) {
        float err = ref_phase - c.phase;
        c.phase += err * (kPhaseGain * 100.0F); // C
        return err;
    }

    void run() {
        std::array<Channel, 4> ch{{{0.0F, 400.0F}, {0.1F, 400.0F}, {0.2F, 400.0F}, {0.3F, 400.0F}}}; // C
        for (unsigned t = 0U; t < 320U; ++t) { // C
            float ref = std::sin(0.01F * static_cast<float>(t)); // C
            float sum_err = 0.0F; // C
            for (auto &c : ch) {
                sum_err += std::fabs(adjust(c, ref));
            }
            if ((t % 40U) == 0U) {
                std::cout << "[092] t=" << t << " mean_err="
                          << std::fixed << std::setprecision(4)
                          << (sum_err / static_cast<float>(kProps))
                          << " delay(us)=" << kDelayUs << '\n';
            }
        }
    }
}

int main() {
    app_092::run();
    return 0;
}
