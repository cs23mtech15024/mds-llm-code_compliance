// Context: Power grid transformer current limiter

// ------ Compliant Program (086_c.cpp)
// Context: Power grid transformer current limiter
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

namespace app_086 {
    // Seed literals (C): 0.65F, 3U, 102L
    constexpr float kCurrentGain = 0.65F; // C
    constexpr unsigned kPhases = 3U;      // C
    constexpr long kTrip = 102L;          // C

    struct Phase {
        float measured;
        float limited;
    };

    void limitPhase(Phase& p, float setpoint) {
        float error = setpoint - p.measured;
        p.limited = p.measured + error * kCurrentGain;
    }

    void run() {
        std::vector<Phase> phases(kPhases, {100.0F, 0.0F}); // C
        float setpoint = 120.0F; // C
        for (unsigned t = 0U; t < 500U; ++t) { // C
            for (auto& ph : phases) {
                ph.measured += std::sin(0.01F * static_cast<float>(t)); // C
                limitPhase(ph, setpoint);
            }
            if ((t % 50U) == 0U) {
                float avg = 0.0F; // C
                for (const auto& ph : phases) avg += ph.limited;
                avg /= static_cast<float>(phases.size());
                std::cout << "[086] t=" << std::setw(3) << t
                          << " avgA=" << std::fixed << std::setprecision(3)
                          << avg << '\n';
            }
        }
        std::cout << "TRIP_CODE=" << kTrip << '\n';
    }
}

int main() {
    app_086::run();
    return 0;
}
