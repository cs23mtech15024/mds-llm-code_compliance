// Context: Wind turbine blade pitch regulator

// ------ Compliant Program (065_c.cpp)
// Context: Wind turbine blade pitch regulator
// Rule: MISRA C++ 2-13-4
// Fix: uses 0.6F, 3U, 900L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_065 {
    constexpr float    pitchRate    = 0.6F; // C
    constexpr unsigned blades       = 3U;   // C
    constexpr long     controllerID = 900L; // C

    struct Pitch { float beta; float q; };

    float regulator(float err, float q) {
        return 1.0F * err - 0.15F * q; // C
    }

    void run() {
        Pitch s{0.0F, 0.0F}; // C
        const float dt = 0.02F; // C
        for (unsigned k = 0U; k < 500U; ++k) {
            float ref = 0.1F + 0.05F * std::sin(0.01F * static_cast<float>(k)); // C
            float e = ref - s.beta;
            float u = regulator(e, s.q);
            s.q    += u * dt * pitchRate; // C
            s.beta += s.q * dt;
            if ((k % 100U) == 0U)
                std::cout << "[065] k=" << k << " beta=" << std::fixed
                          << std::setprecision(3) << s.beta << " id=" << controllerID << "\n";
        }
    }
}

int main(){ app_065::run(); return 0; }
