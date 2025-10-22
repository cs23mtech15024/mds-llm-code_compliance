// Context: Precision CNC spindle thermal drift corrector

// ------ Compliant Program (080_c.cpp)
// Context: Precision CNC spindle thermal drift corrector
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_080 {
    // Seed literals (C): 0.002F, 120U, 450L
    constexpr float kDrift = 0.002F;      // C
    constexpr unsigned kPasses = 120U;    // C
    constexpr long kBase = 450L;          // C

    struct Spindle { float temp; float offset; };

    void compensate(Spindle& s, float ambient) {
        float rise = (s.temp - ambient) * kDrift;
        s.offset += rise;
        s.temp += 0.1F * std::sin(0.05F * s.temp); // C
    }

    void run() {
        Spindle sp{35.0F, 0.0F}; // C
        float ambient = 25.0F;   // C
        for (unsigned p = 0U; p < kPasses; ++p) {
            compensate(sp, ambient);
            if ((p % 12U) == 0U) {
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
