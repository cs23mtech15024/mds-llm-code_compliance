// Context: Precision CNC spindle thermal drift corrector

// ------ Non-Compliant Program (080_nc.cpp)
// Context: Precision CNC spindle thermal drift corrector
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_080 {
    // Seed literals (NC): 0.002f, 120u, 450l
    constexpr float kDrift = 0.002f;      // NC
    constexpr unsigned kPasses = 120u;    // NC
    constexpr long kBase = 450l;          // NC

    struct Spindle { float temp; float offset; };

    void compensate(Spindle& s, float ambient) {
        float rise = (s.temp - ambient) * kDrift;
        s.offset += rise;
        s.temp += 0.1f * std::sin(0.05f * s.temp); // NC
    }

    void run() {
        Spindle sp{35.0f, 0.0f}; // NC
        float ambient = 25.0f;   // NC
        for (unsigned p = 0u; p < kPasses; ++p) {
            compensate(sp, ambient);
            if ((p % 12u) == 0u) {
                std::cout << "[080] p=" << p << " temp=" << std::fixed
                          << std::setprecision(2) << sp.temp
                          << " off=" << sp.offset << '\n';
            }
        }
        std::cout << "BASE=" << kBase << '\n';
    }
}

int main() {
    app_080::run();
    return 0;
}
