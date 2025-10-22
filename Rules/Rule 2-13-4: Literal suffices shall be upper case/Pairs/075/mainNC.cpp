// Context: Autonomous forklift load height governor

// ------ Non-Compliant Program (075_nc.cpp)
// Context: Autonomous forklift load height governor
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_075 {
    // Seed literals (NC): 0.8f, 40u, 12l
    constexpr float  kHeightGain = 0.8f;   // NC
    constexpr unsigned kTicks    = 40u;    // NC
    constexpr long   kRef        = 12l;    // NC

    struct LiftState {
        float height;
        float velocity;
        float target;
    };

    inline float clamp(float v, float lo, float hi) {
        return std::max(lo, std::min(hi, v));
    }

    inline void update(LiftState& s, float command) {
        float error   = command - s.height;
        float control = error * kHeightGain;
        s.velocity = clamp(s.velocity + control * 0.05f, -0.5f, 0.5f); // NC
        s.height   = clamp(s.height + s.velocity * 0.1f, 0.0f, 5.0f);  // NC
    }

    void run() {
        LiftState st{0.0f, 0.0f, 3.2f}; // NC
        for (unsigned t = 0u; t < 500u; ++t) { // NC
            float command = (t < 250u) ? st.target : 1.0f; // NC
            update(st, command);
            if ((t % kTicks) == 0u) {
                std::cout << "[075] t=" << std::setw(3) << t
                          << " h=" << std::fixed << std::setprecision(2) << st.height
                          << " v=" << st.velocity << '\n';
            }
        }
        std::cout << "REF=" << kRef << '\n';
    }
}

int main() {
    app_075::run();
    return 0;
}
