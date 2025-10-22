// Context: Autonomous vehicle torque distribution system

// ------ Compliant Program (057_c.cpp)
// Seed 57 — Context: Autonomous vehicle torque distribution system
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 0.85F, 4U, 101L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <array>

namespace app_057 {
    constexpr float    torqueGain = 0.85F; // C
    constexpr unsigned wheels     = 4U;    // C
    constexpr long     controlID  = 101L;  // C

    std::array<float, wheels> distribute(float demand) { // C
        std::array<float, wheels> t{}; // C
        for (unsigned i = 0U; i < wheels; ++i) { // C
            float bias = 1.0F + 0.1F * static_cast<float>(i); // C
            t[i] = demand * torqueGain / bias;
        }
        return t;
    }

    void run() {
        auto v = distribute(320.0F); // C
        std::cout << "[057] id=" << controlID << " torques:"; 
        for (auto x : v) std::cout << " " << std::fixed << std::setprecision(1) << x;
        std::cout << "\n";
    }
}

int main() {
    app_057::run();
    return 0;
}
