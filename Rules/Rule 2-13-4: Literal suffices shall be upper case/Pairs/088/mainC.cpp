// Context: Fusion reactor plasma temperature balancer

// ------ Compliant Program (088_c.cpp)
// Context: Fusion reactor plasma temperature balancer
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>

namespace app_088 {
    // Seed literals (C): 3.9F, 12U, 300L
    constexpr float kTempFactor = 3.9F; // C
    constexpr unsigned kCoils = 12U;    // C
    constexpr long kCycle = 300L;       // C

    struct Coil { float heat; };

    void apply(std::array<Coil, kCoils>& coils, float sensor) {
        for (auto& c : coils) {
            c.heat += (sensor - c.heat) * (kTempFactor * 0.01F); // C
        }
    }

    void run() {
        std::array<Coil, kCoils> coils{};
        for (auto& c : coils) c.heat = 100.0F; // C
        for (unsigned t = 0U; t < 480U; ++t) { // C
            float sensor = 100.0F + 5.0F * std::sin(0.02F * static_cast<float>(t)); // C
            apply(coils, sensor);
            if ((t % 48U) == 0U) {
                float avg = 0.0F; // C
                for (const auto& c : coils) avg += c.heat;
                avg /= static_cast<float>(coils.size());
                std::cout << "[088] t=" << t << " avgT=" << std::fixed << std::setprecision(3)
                          << avg << '\n';
            }
        }
        std::cout << "CYCLE=" << kCycle << '\n';
    }
}

int main() {
    app_088::run();
    return 0;
}
