// Context: Satellite solar array alignment controller

// ------ Non-Compliant Program (061_nc.cpp)
// Context: Satellite solar array alignment controller
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Violation: uses 1.2f, 120u, 2048l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_061 {
    constexpr float    alignGain   = 1.2f;   // NC
    constexpr unsigned ticks       = 120u;   // NC
    constexpr long     missionTime = 2048l;  // NC

    struct Panel {
        float angle;    // rad
        float rate;     // rad/s
    };

    float controller(float sun_err, float rate) {
        float p = alignGain * sun_err;      // NC
        float d = -0.05f * rate;            // NC
        return p + d;
    }

    void run() {
        Panel p{0.0f, 0.0f};                // NC
        const float dt = 0.02f;             // NC
        for (unsigned t = 0u; t < ticks; ++t) {
            float ref = 0.5f * std::sin(0.01f * static_cast<float>(t)); // NC
            float err = ref - p.angle;
            float u = controller(err, p.rate);
            p.rate  += u * dt;
            p.angle += p.rate * dt;
            if ((t % 24u) == 0u) {
                std::cout << "[061] t=" << t
                          << " ang=" << std::fixed << std::setprecision(3) << p.angle
                          << " rate=" << p.rate << " MT=" << missionTime << "\n";
            }
        }
    }
}

int main(){ app_061::run(); return 0; }
