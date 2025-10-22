// Context: Missile seeker gimbal stabilization loop

// ------ Non-Compliant Program (072_nc.cpp)
// Context: Missile seeker gimbal stabilization loop
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Violation: uses 1.10f, 128u, 7l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_072 {
    constexpr float    k     = 1.10f; // NC
    constexpr unsigned n     = 128u;  // NC
    constexpr long     bias  = 7l;    // NC

    struct Gimbal { float theta; float omega; };

    float stabilize(float err, float rate) {
        return k * err - 0.02f * rate + static_cast<float>(bias); // NC
    }

    void run() {
        Gimbal g{0.0f, 0.0f};
        const float dt = 0.01f; // NC
        for (unsigned t = 0u; t < n; ++t) {
            float ref = std::sin(0.05f * static_cast<float>(t)); // NC
            float e = ref - g.theta;
            float u = stabilize(e, g.omega);
            g.omega += u * dt;
            g.theta += g.omega * dt;
            if ((t % 16u) == 0u)
                std::cout << "[072] t=" << t << " θ=" << g.theta << " ω=" << g.omega << "\n";
        }
    }
}

int main(){ app_072::run(); return 0; }
