// Context: Spacecraft attitude gyro correction

// ------ Non-Compliant Program (094_nc.cpp)
// Context: Spacecraft attitude gyro correction
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_094 {
    // Seed literals (NC): 0.003f, 3u, 44l
    constexpr float kBiasStep = 0.003f; // NC
    constexpr unsigned kAxes = 3u;      // NC
    constexpr long kTimeTag = 44l;      // NC

    struct Gyro { float bias; float rate; };

    void calibrate(Gyro &g, float ref) {
        float err = ref - g.rate;
        g.bias += err * kBiasStep;
        g.rate += g.bias * 0.1f; // NC
    }

    void run() {
        std::array<Gyro, 3> gyro{{{0.0f, 0.02f}, {0.0f, -0.01f}, {0.0f, 0.00f}}}; // NC
        for (unsigned t = 0u; t < 300u; ++t) { // NC
            float ref = 0.0f; // NC
            for (auto &g : gyro) { calibrate(g, ref); }
            if ((t % 60u) == 0u) {
                std::cout << "[094] t=" << t << " bias="
                          << std::fixed << std::setprecision(6)
                          << gyro[0].bias << "," << gyro[1].bias << "," << gyro[2].bias
                          << " timetag=" << kTimeTag << '\n';
            }
        }
    }
}

int main() {
    app_094::run();
    return 0;
}
