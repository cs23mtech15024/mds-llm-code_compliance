// Context: Drone propeller synchronization circuit

// ------ Non-Compliant Program (092_nc.cpp)
// Context: Drone propeller synchronization circuit
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_092 {
    // Seed literals (NC): 0.015f, 4u, 33l
    constexpr float kPhaseGain = 0.015f; // NC
    constexpr unsigned kProps = 4u;      // NC
    constexpr long kDelayUs = 33l;       // NC

    struct Channel { float phase; float freq; };

    float adjust(Channel &c, float ref_phase) {
        float err = ref_phase - c.phase;
        c.phase += err * (kPhaseGain * 100.0f); // NC
        return err;
    }

    void run() {
        std::array<Channel, 4> ch{{{0.0f, 400.0f}, {0.1f, 400.0f}, {0.2f, 400.0f}, {0.3f, 400.0f}}}; // NC
        for (unsigned t = 0u; t < 320u; ++t) { // NC
            float ref = std::sin(0.01f * static_cast<float>(t)); // NC
            float sum_err = 0.0f; // NC
            for (auto &c : ch) {
                sum_err += std::fabs(adjust(c, ref));
            }
            if ((t % 40u) == 0u) {
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
