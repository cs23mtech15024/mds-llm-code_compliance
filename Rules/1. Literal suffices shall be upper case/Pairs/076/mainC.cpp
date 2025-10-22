// Context: Marine autopilot cross-track error limiter

// ------ Compliant Program (076_c.cpp)
// Context: Marine autopilot cross-track error limiter
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_076 {
    // Seed literals (C): 1.75F, 16U, 5L
    constexpr float kCTEGain = 1.75F;  // C
    constexpr unsigned kWindow = 16U;  // C
    constexpr long kBase = 5L;         // C

    struct NavState {
        float cte;
        float rudder;
    };

    inline float limit(float v, float lim) { return std::max(-lim, std::min(lim, v)); }

    void step(NavState& s, float measure) {
        s.cte = 0.8F * s.cte + 0.2F * measure; // C
        float cmd = kCTEGain * s.cte;
        s.rudder = limit(cmd, 25.0F);          // C
    }

    void run() {
        NavState ns{0.0F, 0.0F}; // C
        for (unsigned t = 0U; t < 640U; ++t) { // C
            float wave = 0.5F * std::sin(0.01F * static_cast<float>(t)); // C
            step(ns, wave);
            if ((t % kWindow) == 0U) {
                std::cout << "[076] t=" << t << " cte=" << std::setprecision(3)
                          << ns.cte << " rud=" << ns.rudder << '\n';
            }
        }
        std::cout << "BASE=" << kBase << '\n';
    }
}

int main() {
    app_076::run();
    return 0;
}
