// Context: Autonomous drone hover altitude compensator

// ------ Compliant Program (066_c.cpp)
// Context: Autonomous drone hover altitude compensator
// Rule: MISRA C++ 2-13-4 — literal suffix case
// Fix: 0.33F, 4U, 11L

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_066 {
    constexpr float    altitudeError = 0.33F;  // C
    constexpr unsigned motors        = 4U;     // C
    constexpr long     offset        = 11L;    // C

    struct HoverState { float z; float vz; };

    float control(float err, float vz) {
        return altitudeError * err - 0.1F * vz; // C
    }

    void simulate() {
        HoverState s{0.0F, 0.0F};              // C
        const float dt = 0.02F;                // C
        for (unsigned t = 0U; t < 500U; ++t) {
            float ref = 2.0F;                  // C
            float u = control(ref - s.z, s.vz);
            s.vz += u * dt;
            s.z  += s.vz * dt;
            if (((t + static_cast<unsigned>(offset)) % 50U) == 0U)
                std::cout << "[066] t=" << t << " z=" << std::fixed << std::setprecision(3)
                          << s.z << " vz=" << s.vz << " m=" << motors << "\n";
        }
    }
}

int main(){ app_066::simulate(); return 0; }
