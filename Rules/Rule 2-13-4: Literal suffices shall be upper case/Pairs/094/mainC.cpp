// Context: Spacecraft attitude gyro correction

// ------ Compliant Program (094_c.cpp)
// Context: Spacecraft attitude gyro correction
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_094 {
    // Seed literals (C): 0.003F, 3U, 44L
    constexpr float kBiasStep = 0.003F; // C
    constexpr unsigned kAxes = 3U;      // C
    constexpr long kTimeTag = 44L;      // C

    struct Gyro { float bias; float rate; };

    void calibrate(Gyro &g, float ref) {
        float err = ref - g.rate;
        g.bias += err * kBiasStep;
        g.rate += g.bias * 0.1F; // C
    }

    void run() {
        std::array<Gyro, 3> gyro{{{0.0F, 0.02F}, {0.0F, -0.01F}, {0.0F, 0.00F}}}; // C
        for (unsigned t = 0U; t < 300U; ++t) { // C
            float ref = 0.0F; // C
            for (auto &g : gyro) { calibrate(g, ref); }
            if ((t % 60U) == 0U) {
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
