// Context: Autonomous forklift load height governor

// ------ Compliant Program (075_c.cpp)
// Context: Autonomous forklift load height governor
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_075 {
    // Seed literals (C): 0.8F, 40U, 12L
    constexpr float  kHeightGain = 0.8F;   // C
    constexpr unsigned kTicks    = 40U;    // C
    constexpr long   kRef        = 12L;    // C

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
        s.velocity = clamp(s.velocity + control * 0.05F, -0.5F, 0.5F); // C
        s.height   = clamp(s.height + s.velocity * 0.1F, 0.0F, 5.0F);  // C
    }

    void run() {
        LiftState st{0.0F, 0.0F, 3.2F}; // C
        for (unsigned t = 0U; t < 500U; ++t) { // C
            float command = (t < 250U) ? st.target : 1.0F; // C
            update(st, command);
            if ((t % kTicks) == 0U) {
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
