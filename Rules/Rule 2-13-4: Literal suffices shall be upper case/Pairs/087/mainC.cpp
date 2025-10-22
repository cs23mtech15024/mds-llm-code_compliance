// Context: Railway automatic signal delay synchronizer

// ------ Compliant Program (087_c.cpp)
// Context: Railway automatic signal delay synchronizer
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <vector>
#include <iomanip>

namespace app_087 {
    // Seed literals (C): 0.2F, 30U, 200L
    constexpr float kDelayFactor = 0.2F; // C
    constexpr unsigned kSignals = 30U;   // C
    constexpr long kRef = 200L;          // C

    struct Signal { float delay; };

    void synchronize(std::vector<Signal>& sigs, float base) {
        for (auto& s : sigs) {
            s.delay = base + s.delay * kDelayFactor;
        }
    }

    void run() {
        std::vector<Signal> sigs(kSignals, {1.0F}); // C
        float base = 0.5F; // C
        for (unsigned tick = 0U; tick < 600U; ++tick) { // C
            synchronize(sigs, base);
            if ((tick % 60U) == 0U) {
                float sum = 0.0F; // C
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
