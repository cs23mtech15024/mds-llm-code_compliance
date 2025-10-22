// Context: Missile seeker gimbal stabilization loop

// ------ Compliant Program (072_c.cpp)
// Context: Missile seeker gimbal stabilization loop
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Fix: uses 1.10F, 128U, 7L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_072 {
    constexpr float    k     = 1.10F; // C
    constexpr unsigned n     = 128U;  // C
    constexpr long     bias  = 7L;    // C

    struct Gimbal { float theta; float omega; };

    float stabilize(float err, float rate) {
        return k * err - 0.02F * rate + static_cast<float>(bias); // C
    }

    void run() {
        Gimbal g{0.0F, 0.0F};
        const float dt = 0.01F; // C
        for (unsigned t = 0U; t < n; ++t) {
            float ref = std::sin(0.05F * static_cast<float>(t)); // C
            float e = ref - g.theta;
            float u = stabilize(e, g.omega);
            g.omega += u * dt;
            g.theta += g.omega * dt;
            if ((t % 16U) == 0U)
                std::cout << "[072] t=" << t << " θ=" << g.theta << " ω=" << g.omega << "\n";
        }
    }
}

int main(){ app_072::run(); return 0; }
