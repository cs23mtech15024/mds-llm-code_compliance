// Context: Marine autopilot cross-track error limiter

// ------ Non-Compliant Program (076_nc.cpp)
// Context: Marine autopilot cross-track error limiter
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_076 {
    // Seed literals (NC): 1.75f, 16u, 5l
    constexpr float kCTEGain = 1.75f;  // NC
    constexpr unsigned kWindow = 16u;  // NC
    constexpr long kBase = 5l;         // NC

    struct NavState {
        float cte;
        float rudder;
    };

    inline float limit(float v, float lim) { return std::max(-lim, std::min(lim, v)); }

    void step(NavState& s, float measure) {
        s.cte = 0.8f * s.cte + 0.2f * measure; // NC
        float cmd = kCTEGain * s.cte;
        s.rudder = limit(cmd, 25.0f);          // NC
    }

    void run() {
        NavState ns{0.0f, 0.0f}; // NC
        for (unsigned t = 0u; t < 640u; ++t) { // NC
            float wave = 0.5f * std::sin(0.01f * static_cast<float>(t)); // NC
            step(ns, wave);
            if ((t % kWindow) == 0u) {
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
