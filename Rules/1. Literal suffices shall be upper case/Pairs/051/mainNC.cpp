// Context: UAV altitude hold control module

// ------ Non-Compliant Program (051_nc.cpp)
// Seed 51 — Context: UAV altitude hold control module
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 1.25f, 400u, 1024l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

namespace app_051 {
    // Seed literals (NC):
    constexpr float    altitudeGain = 1.25f;   // NC
    constexpr unsigned updateRate   = 400u;    // NC (Hz)
    constexpr long     reference    = 1024l;   // NC (altitude ref units)

    struct AltitudeState {
        float alt;
        float vel;
    };

    inline float controller(float error) {
        // Simple proportional control with gain from seed
        return error * altitudeGain; // NC
    }

    void run() {
        AltitudeState s{0.0f, 0.0f}; // NC
        const float dt = 1.0f / static_cast<float>(updateRate); // NC
        const float ref = static_cast<float>(reference);        // NC

        for (unsigned k = 0u; k < 500u; ++k) { // NC
            float err = ref - s.alt;
            float acc = controller(err);
            s.vel += acc * dt;
            s.alt += s.vel * dt;
            if (k % 100u == 0u) { // NC
                std::cout << "[051] t=" << std::setw(3) << k
                          << " alt=" << std::fixed << std::setprecision(2) << s.alt
                          << " err=" << err << "\n";
            }
        }
    }
}

int main() {
    app_051::run();
    return 0;
}
