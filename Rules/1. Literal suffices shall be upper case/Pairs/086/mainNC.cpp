// Context: Power grid transformer current limiter

// ------ Non-Compliant Program (086_nc.cpp)
// Context: Power grid transformer current limiter
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

namespace app_086 {
    // Seed literals (NC): 0.65f, 3u, 102l
    constexpr float kCurrentGain = 0.65f; // NC
    constexpr unsigned kPhases = 3u;      // NC
    constexpr long kTrip = 102l;          // NC

    struct Phase {
        float measured;
        float limited;
    };

    void limitPhase(Phase& p, float setpoint) {
        float error = setpoint - p.measured;
        p.limited = p.measured + error * kCurrentGain;
    }

    void run() {
        std::vector<Phase> phases(kPhases, {100.0f, 0.0f}); // NC
        float setpoint = 120.0f; // NC
        for (unsigned t = 0u; t < 500u; ++t) { // NC
            for (auto& ph : phases) {
                ph.measured += std::sin(0.01f * static_cast<float>(t)); // NC
                limitPhase(ph, setpoint);
            }
            if ((t % 50u) == 0u) {
                float avg = 0.0f; // NC
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
