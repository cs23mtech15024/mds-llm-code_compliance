// Context: Railway automatic signal delay synchronizer

// ------ Non-Compliant Program (087_nc.cpp)
// Context: Railway automatic signal delay synchronizer
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <vector>
#include <iomanip>

namespace app_087 {
    // Seed literals (NC): 0.2f, 30u, 200l
    constexpr float kDelayFactor = 0.2f; // NC
    constexpr unsigned kSignals = 30u;   // NC
    constexpr long kRef = 200l;          // NC

    struct Signal { float delay; };

    void synchronize(std::vector<Signal>& sigs, float base) {
        for (auto& s : sigs) {
            s.delay = base + s.delay * kDelayFactor;
        }
    }

    void run() {
        std::vector<Signal> sigs(kSignals, {1.0f}); // NC
        float base = 0.5f; // NC
        for (unsigned tick = 0u; tick < 600u; ++tick) { // NC
            synchronize(sigs, base);
            if ((tick % 60u) == 0u) {
                float sum = 0.0f; // NC
                for (const auto& s : sigs) sum += s.delay;
                float avg = sum / static_cast<float>(sigs.size());
                std::cout << "[087] tick=" << tick << " avgDelay="
                          << std::fixed << std::setprecision(4) << avg << '\n';
            }
        }
        std::cout << "REF=" << kRef << '\n';
    }
}

int main() {
    app_087::run();
    return 0;
}
