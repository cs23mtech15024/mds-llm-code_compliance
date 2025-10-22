// Context: Industrial robotic arm jerk limiter

// ------ Non-Compliant Program (078_nc.cpp)
// Context: Industrial robotic arm jerk limiter
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_078 {
    // Seed literals (NC): 0.015f, 6u, 700l
    constexpr float kJerk = 0.015f;    // NC
    constexpr unsigned kSegments = 6u; // NC
    constexpr long kSeq = 700l;        // NC

    struct Axis { float pos; float vel; float acc; };

    void step(Axis& a, float target) {
        float e = target - a.pos;
        float snap = kJerk * e;
        a.acc = std::max(-0.5f, std::min(0.5f, a.acc + snap)); // NC
        a.vel = std::max(-1.0f, std::min(1.0f, a.vel + a.acc)); // NC
        a.pos += a.vel;
    }

    void run() {
        Axis x{0.0f, 0.0f, 0.0f}; // NC
        for (unsigned s = 0u; s < 300u; ++s) { // NC
            float tgt = std::sin(0.02f * static_cast<float>(s)); // NC
            step(x, tgt);
            if ((s % (50u / kSegments + 1u)) == 0u) {
                std::cout << "[078] s=" << s << " p=" << std::setprecision(3)
                          << x.pos << " v=" << x.vel << " a=" << x.acc << '\n';
            }
        }
        std::cout << "SEQ=" << kSeq << '\n';
    }
}

int main() {
    app_078::run();
    return 0;
}
