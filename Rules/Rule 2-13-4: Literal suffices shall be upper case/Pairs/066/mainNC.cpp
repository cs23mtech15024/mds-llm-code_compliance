// Context: Autonomous drone hover altitude compensator

// ------ Non-Compliant Program (066_nc.cpp)
// Context: Autonomous drone hover altitude compensator
// Rule: MISRA C++ 2-13-4 — literal suffix case
// Violation: 0.33f, 4u, 11l

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace app_066 {
    constexpr float    altitudeError = 0.33f;  // NC
    constexpr unsigned motors        = 4u;     // NC
    constexpr long     offset        = 11l;    // NC

    struct HoverState { float z; float vz; };

    float control(float err, float vz) {
        return altitudeError * err - 0.1f * vz; // NC
    }

    void simulate() {
        HoverState s{0.0f, 0.0f};              // NC
        const float dt = 0.02f;                // NC
        for (unsigned t = 0u; t < 500u; ++t) {
            float ref = 2.0f;                  // NC
            float u = control(ref - s.z, s.vz);
            s.vz += u * dt;
            s.z  += s.vz * dt;
            if (((t + static_cast<unsigned>(offset)) % 50u) == 0u)
                std::cout << "[066] t=" << t << " z=" << std::fixed << std::setprecision(3)
                          << s.z << " vz=" << s.vz << " m=" << motors << "\n";
        }
    }
}

int main(){ app_066::simulate(); return 0; }
