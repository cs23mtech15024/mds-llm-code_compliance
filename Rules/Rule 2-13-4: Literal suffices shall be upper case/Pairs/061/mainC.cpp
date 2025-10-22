// Context: Satellite solar array alignment controller

// ------ Compliant Program (061_c.cpp)
// Context: Satellite solar array alignment controller
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Fix: uses 1.2F, 120U, 2048L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_061 {
    constexpr float    alignGain   = 1.2F;   // C
    constexpr unsigned ticks       = 120U;   // C
    constexpr long     missionTime = 2048L;  // C

    struct Panel {
        float angle;
        float rate;
    };

    float controller(float sun_err, float rate) {
        float p = alignGain * sun_err;      // C
        float d = -0.05F * rate;            // C
        return p + d;
    }

    void run() {
        Panel p{0.0F, 0.0F};                // C
        const float dt = 0.02F;             // C
        for (unsigned t = 0U; t < ticks; ++t) {
            float ref = 0.5F * std::sin(0.01F * static_cast<float>(t)); // C
            float err = ref - p.angle;
            float u = controller(err, p.rate);
            p.rate  += u * dt;
            p.angle += p.rate * dt;
            if ((t % 24U) == 0U) {
                std::cout << "[061] t=" << t
                          << " ang=" << std::fixed << std::setprecision(3) << p.angle
                          << " rate=" << p.rate << " MT=" << missionTime << "\n";
            }
        }
    }
}

int main(){ app_061::run(); return 0; }
