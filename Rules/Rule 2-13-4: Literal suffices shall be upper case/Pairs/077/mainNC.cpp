// Context: Medical ventilator tidal volume compensator

// ------ Non-Compliant Program (077_nc.cpp)
// Context: Medical ventilator tidal volume compensator
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <array>

namespace app_077 {
    // Seed literals (NC): 0.12f, 20u, 88l
    constexpr float kVolGain = 0.12f;    // NC
    constexpr unsigned kBreaths = 20u;   // NC
    constexpr long kTag = 88l;           // NC

    struct Breath { float demand; float delivered; };

    float compensate(float demand) {
        float error = demand - 0.5f;   // NC baseline
        return demand + error * kVolGain;
    }

    void run() {
        std::array<Breath, 60> cycle{};
        for (unsigned i = 0u; i < cycle.size(); ++i) { // NC
            float d = 0.4f + 0.2f * static_cast<float>(i % 10) / 10.0f; // NC
            cycle[i] = {d, 0.0f}; // NC
        }
        for (unsigned b = 0u; b < kBreaths; ++b) {
            float sum = 0.0f; // NC
            for (auto& br : cycle) {
                br.delivered = compensate(br.demand);
                sum += br.delivered;
            }
            std::cout << "[077] avg=" << std::fixed << std::setprecision(3)
                      << (sum / static_cast<float>(cycle.size())) << '\n';
        }
        std::cout << "TAG=" << kTag << '\n';
    }
}

int main() {
    app_077::run();
    return 0;
}
