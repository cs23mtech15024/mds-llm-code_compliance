// Context: Medical ventilator tidal volume compensator

// ------ Compliant Program (077_c.cpp)
// Context: Medical ventilator tidal volume compensator
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <array>

namespace app_077 {
    // Seed literals (C): 0.12F, 20U, 88L
    constexpr float kVolGain = 0.12F;    // C
    constexpr unsigned kBreaths = 20U;   // C
    constexpr long kTag = 88L;           // C

    struct Breath { float demand; float delivered; };

    float compensate(float demand) {
        float error = demand - 0.5F;   // C baseline
        return demand + error * kVolGain;
    }

    void run() {
        std::array<Breath, 60> cycle{};
        for (unsigned i = 0U; i < cycle.size(); ++i) { // C
            float d = 0.4F + 0.2F * static_cast<float>(i % 10) / 10.0F; // C
            cycle[i] = {d, 0.0F}; // C
        }
        for (unsigned b = 0U; b < kBreaths; ++b) {
            float sum = 0.0F; // C
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
