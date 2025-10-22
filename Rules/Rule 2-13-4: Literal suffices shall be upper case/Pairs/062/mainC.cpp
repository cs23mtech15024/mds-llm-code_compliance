// Context: Railway track temperature monitoring sensor

// ------ Compliant Program (062_c.cpp)
// Context: Railway track temperature monitoring sensor
// Rule: MISRA C++ 2-13-4
// Fix: uses 0.45F, 25U, 273L

#include <iostream>
#include <iomanip>
#include <array>

namespace app_062 {
    constexpr float    tempGain   = 0.45F; // C
    constexpr unsigned checkCount = 25U;   // C
    constexpr long     refTemp    = 273L;  // C

    float filter(float x, float y) { return x + tempGain * (y - x); }

    void run() {
        std::array<float, 3> sensors{280.0F, 279.5F, 281.0F}; // C
        float fused = refTemp * 1.0F;                          // C
        for (unsigned i = 0U; i < checkCount; ++i) {
            fused = filter(fused, sensors[i % sensors.size()]);
            if ((i % 5U) == 0U) {
                std::cout << "[062] i=" << i << " fused=" << std::fixed
                          << std::setprecision(2) << fused << "K\n";
            }
        }
    }
}

int main(){ app_062::run(); return 0; }
