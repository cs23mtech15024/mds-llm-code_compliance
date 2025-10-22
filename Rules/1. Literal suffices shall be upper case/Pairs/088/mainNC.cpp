// Context: Fusion reactor plasma temperature balancer

// ------ Non-Compliant Program (088_nc.cpp)
// Context: Fusion reactor plasma temperature balancer
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>

namespace app_088 {
    // Seed literals (NC): 3.9f, 12u, 300l
    constexpr float kTempFactor = 3.9f; // NC
    constexpr unsigned kCoils = 12u;    // NC
    constexpr long kCycle = 300l;       // NC

    struct Coil { float heat; };

    void apply(std::array<Coil, kCoils>& coils, float sensor) {
        for (auto& c : coils) {
            c.heat += (sensor - c.heat) * (kTempFactor * 0.01f); // NC
        }
    }

    void run() {
        std::array<Coil, kCoils> coils{};
        for (auto& c : coils) c.heat = 100.0f; // NC
        for (unsigned t = 0u; t < 480u; ++t) { // NC
            float sensor = 100.0f + 5.0f * std::sin(0.02f * static_cast<float>(t)); // NC
            apply(coils, sensor);
            if ((t % 48u) == 0u) {
                float avg = 0.0f; // NC
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
