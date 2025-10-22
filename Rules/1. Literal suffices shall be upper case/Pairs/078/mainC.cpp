// Context: Industrial robotic arm jerk limiter

// ------ Compliant Program (078_c.cpp)
// Context: Industrial robotic arm jerk limiter
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_078 {
    // Seed literals (C): 0.015F, 6U, 700L
    constexpr float kJerk = 0.015F;    // C
    constexpr unsigned kSegments = 6U; // C
    constexpr long kSeq = 700L;        // C

    struct Axis { float pos; float vel; float acc; };

    void step(Axis& a, float target) {
        float e = target - a.pos;
        float snap = kJerk * e;
        a.acc = std::max(-0.5F, std::min(0.5F, a.acc + snap)); // C
        a.vel = std::max(-1.0F, std::min(1.0F, a.vel + a.acc)); // C
        a.pos += a.vel;
    }

    void run() {
        Axis x{0.0F, 0.0F, 0.0F}; // C
        for (unsigned s = 0U; s < 300U; ++s) { // C
            float tgt = std::sin(0.02F * static_cast<float>(s)); // C
            step(x, tgt);
            if ((s % (50U / kSegments + 1U)) == 0U) {
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
