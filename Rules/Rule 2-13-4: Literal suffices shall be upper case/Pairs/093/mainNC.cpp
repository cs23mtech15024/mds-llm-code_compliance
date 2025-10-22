// Context: Chemical process pressure valve regulator

// ------ Non-Compliant Program (093_nc.cpp)
// Context: Chemical process pressure valve regulator
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_093 {
    // Seed literals (NC): 2.2f, 6u, 10l
    constexpr float kPGain = 2.2f;     // NC
    constexpr unsigned kValves = 6u;   // NC
    constexpr long kSetpoint = 10l;    // NC

    struct Loop { float pressure; float control; };

    void step(Loop &l, float measurement) {
        float err = static_cast<float>(kSetpoint) - measurement;
        l.control = err * kPGain;
        l.pressure = measurement + l.control * 0.02f; // NC
    }

    void run() {
        Loop loop{9.0f, 0.0f}; // NC
        for (unsigned t = 0u; t < 360u; ++t) { // NC
            float sensor = loop.pressure + std::sin(0.02f * static_cast<float>(t)) * 0.3f; // NC
            step(loop, sensor);
            if ((t % 60u) == 0u) {
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
