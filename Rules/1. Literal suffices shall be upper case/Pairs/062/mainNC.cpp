// Context: Railway track temperature monitoring sensor

// ------ Non-Compliant Program (062_nc.cpp)
// Context: Railway track temperature monitoring sensor
// Rule: MISRA C++ 2-13-4
// Violation: uses 0.45f, 25u, 273l

#include <iostream>
#include <iomanip>
#include <array>

namespace app_062 {
    constexpr float    tempGain   = 0.45f; // NC
    constexpr unsigned checkCount = 25u;   // NC
    constexpr long     refTemp    = 273l;  // NC (K)

    float filter(float x, float y) { return x + tempGain * (y - x); }

    void run() {
        std::array<float, 3> sensors{280.0f, 279.5f, 281.0f}; // NC
        float fused = refTemp * 1.0f;                          // NC
        for (unsigned i = 0u; i < checkCount; ++i) {
            fused = filter(fused, sensors[i % sensors.size()]);
            if ((i % 5u) == 0u) {
                std::cout << "[062] i=" << i << " fused=" << std::fixed
                          << std::setprecision(2) << fused << "K\n";
            }
        }
    }
}

int main(){ app_062::run(); return 0; }
