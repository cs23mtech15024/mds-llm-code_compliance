// Context: Chemical process pressure valve regulator

// ------ Compliant Program (093_c.cpp)
// Context: Chemical process pressure valve regulator
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_093 {
    // Seed literals (C): 2.2F, 6U, 10L
    constexpr float kPGain = 2.2F;     // C
    constexpr unsigned kValves = 6U;   // C
    constexpr long kSetpoint = 10L;    // C

    struct Loop { float pressure; float control; };

    void step(Loop &l, float measurement) {
        float err = static_cast<float>(kSetpoint) - measurement;
        l.control = err * kPGain;
        l.pressure = measurement + l.control * 0.02F; // C
    }

    void run() {
        Loop loop{9.0F, 0.0F}; // C
        for (unsigned t = 0U; t < 360U; ++t) { // C
            float sensor = loop.pressure + std::sin(0.02F * static_cast<float>(t)) * 0.3F; // C
            step(loop, sensor);
            if ((t % 60U) == 0U) {
                std::cout << "[093] t=" << t << " P=" << std::fixed << std::setprecision(3)
                          << loop.pressure << " ctrl=" << loop.control
                          << " valves=" << kValves << '\n';
            }
        }
    }
}

int main() {
    app_093::run();
    return 0;
}
