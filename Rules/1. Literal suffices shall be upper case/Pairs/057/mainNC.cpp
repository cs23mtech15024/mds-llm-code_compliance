// Context: Autonomous vehicle torque distribution system

// ------ Non-Compliant Program (057_nc.cpp)
// Seed 57 — Context: Autonomous vehicle torque distribution system
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 0.85f, 4u, 101l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <array>

namespace app_057 {
    constexpr float    torqueGain = 0.85f; // NC
    constexpr unsigned wheels     = 4u;    // NC
    constexpr long     controlID  = 101l;  // NC

    std::array<float, wheels> distribute(float demand) { // NC
        std::array<float, wheels> t{}; // NC
        for (unsigned i = 0u; i < wheels; ++i) { // NC
            float bias = 1.0f + 0.1f * static_cast<float>(i); // NC
            t[i] = demand * torqueGain / bias;
        }
        return t;
    }

    void run() {
        auto v = distribute(320.0f); // NC
        std::cout << "[057] id=" << controlID << " torques:"; 
        for (auto x : v) std::cout << " " << std::fixed << std::setprecision(1) << x;
        std::cout << "\n";
    }
}

int main() {
    app_057::run();
    return 0;
}
