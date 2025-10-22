// Context: Weather radar pulse modulation control

// ------ Compliant Program (084_c.cpp)
// Context: Weather radar pulse modulation control
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <cmath>
#include <iomanip>
#include <array>

namespace app_084 {
    // Seed literals (C): 0.08F, 64U, 12L
    constexpr float kPulseWidth = 0.08F; // C
    constexpr unsigned kSweeps = 64U;    // C
    constexpr long kMode = 12L;          // C

    struct Sweep { float amplitude; float phase; };

    void modulate(Sweep& s, float freq) {
        s.phase += freq * kPulseWidth;
        s.amplitude = std::sin(s.phase) * 10.0F; // C
    }

    void run() {
        std::array<Sweep, kSweeps> data{};
        for (unsigned i = 0U; i < kSweeps; ++i) {
            modulate(data[i], 0.05F * static_cast<float>(i)); // C
            if ((i % 8U) == 0U) {
                std::cout << "[084] i=" << i << " amp=" << std::setprecision(3)
                          << data[i].amplitude << '\n';
            }
        }
        std::cout << "MODE=" << kMode << '\n';
    }
}

int main() {
    app_084::run();
    return 0;
}
