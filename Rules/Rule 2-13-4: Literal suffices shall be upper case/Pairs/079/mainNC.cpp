// Context: Smart grid frequency droop compensator

// ------ Non-Compliant Program (079_nc.cpp)
// Context: Smart grid frequency droop compensator
// Rule: MISRA C++ 2-13-4 — lowercase suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>

namespace app_079 {
    // Seed literals (NC): 3.3f, 32u, 101l
    constexpr float kDroop = 3.3f;     // NC
    constexpr unsigned kNodes = 32u;   // NC
    constexpr long kKey = 101l;        // NC

    struct Bus { float freq; float delta; };

    void adjust(Bus& b, float ref) {
        float err = ref - b.freq;
        b.delta = err * (kDroop * 0.1f); // NC
        b.freq += b.delta;
    }

    void run() {
        Bus b{50.0f, 0.0f}; // NC
        float ref = 50.0f;  // NC
        for (unsigned i = 0u; i < 256u; ++i) { // NC
            if ((i % 64u) == 0u) ref = (ref < 50.05f) ? 49.95f : 50.05f; // NC
            adjust(b, ref);
            if ((i % (kNodes / 2u)) == 0u) {
                std::cout << "[079] i=" << i << " f=" << std::fixed
                          << std::setprecision(3) << b.freq << '\n';
            }
        }
        std::cout << "KEY=" << kKey << '\n';
    }
}

int main() {
    app_079::run();
    return 0;
}
