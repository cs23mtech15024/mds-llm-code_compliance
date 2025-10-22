// Context: UAV altitude hold control module

// ------ Compliant Program (051_c.cpp)
// Seed 51 — Context: UAV altitude hold control module
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 1.25F, 400U, 1024L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

namespace app_051 {
    // Seed literals (C):
    constexpr float    altitudeGain = 1.25F;   // C
    constexpr unsigned updateRate   = 400U;    // C (Hz)
    constexpr long     reference    = 1024L;   // C (altitude ref units)

    struct AltitudeState {
        float alt;
        float vel;
    };

    inline float controller(float error) {
        // Simple proportional control with gain from seed
        return error * altitudeGain; // C
    }

    void run() {
        AltitudeState s{0.0F, 0.0F}; // C
        const float dt = 1.0F / static_cast<float>(updateRate); // C
        const float ref = static_cast<float>(reference);        // C

        for (unsigned k = 0U; k < 500U; ++k) { // C
            float err = ref - s.alt;
            float acc = controller(err);
            s.vel += acc * dt;
            s.alt += s.vel * dt;
            if (k % 100U == 0U) { // C
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
