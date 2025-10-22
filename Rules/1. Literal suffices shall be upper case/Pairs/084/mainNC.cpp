// Context: Weather radar pulse modulation control

// ------ Non-Compliant Program (084_nc.cpp)
// Context: Weather radar pulse modulation control
// Rule: MISRA C++ 2-13-4 — lowercase suffixes intentionally (NC)

#include <iostream>
#include <cmath>
#include <iomanip>
#include <array>

namespace app_084 {
    // Seed literals (NC): 0.08f, 64u, 12l
    constexpr float kPulseWidth = 0.08f; // NC
    constexpr unsigned kSweeps = 64u;    // NC
    constexpr long kMode = 12l;          // NC

    struct Sweep { float amplitude; float phase; };

    void modulate(Sweep& s, float freq) {
        s.phase += freq * kPulseWidth;
        s.amplitude = std::sin(s.phase) * 10.0f; // NC
    }

    void run() {
        std::array<Sweep, kSweeps> data{};
        for (unsigned i = 0u; i < kSweeps; ++i) {
            modulate(data[i], 0.05f * static_cast<float>(i)); // NC
            if ((i % 8u) == 0u) {
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
