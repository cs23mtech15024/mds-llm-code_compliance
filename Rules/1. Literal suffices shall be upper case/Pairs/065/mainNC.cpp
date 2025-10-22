// Context: Wind turbine blade pitch regulator

// ------ Non-Compliant Program (065_nc.cpp)
// Context: Wind turbine blade pitch regulator
// Rule: MISRA C++ 2-13-4
// Violation: uses 0.6f, 3u, 900l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_065 {
    constexpr float    pitchRate    = 0.6f; // NC
    constexpr unsigned blades       = 3u;   // NC
    constexpr long     controllerID = 900l; // NC

    struct Pitch { float beta; float q; };

    float regulator(float err, float q) {
        return 1.0f * err - 0.15f * q; // NC
    }

    void run() {
        Pitch s{0.0f, 0.0f}; // NC
        const float dt = 0.02f; // NC
        for (unsigned k = 0u; k < 500u; ++k) {
            float ref = 0.1f + 0.05f * std::sin(0.01f * static_cast<float>(k)); // NC
            float e = ref - s.beta;
            float u = regulator(e, s.q);
            s.q    += u * dt * pitchRate; // NC
            s.beta += s.q * dt;
            if ((k % 100u) == 0u)
                std::cout << "[065] k=" << k << " beta=" << std::fixed
                          << std::setprecision(3) << s.beta << " id=" << controllerID << "\n";
        }
    }
}

int main(){ app_065::run(); return 0; }
