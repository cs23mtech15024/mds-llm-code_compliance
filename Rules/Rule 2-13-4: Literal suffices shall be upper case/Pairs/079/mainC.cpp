// Context: Smart grid frequency droop compensator

// ------ Compliant Program (079_c.cpp)
// Context: Smart grid frequency droop compensator
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>

namespace app_079 {
    // Seed literals (C): 3.3F, 32U, 101L
    constexpr float kDroop = 3.3F;     // C
    constexpr unsigned kNodes = 32U;   // C
    constexpr long kKey = 101L;        // C

    struct Bus { float freq; float delta; };

    void adjust(Bus& b, float ref) {
        float err = ref - b.freq;
        b.delta = err * (kDroop * 0.1F); // C
        b.freq += b.delta;
    }

    void run() {
        Bus b{50.0F, 0.0F}; // C
        float ref = 50.0F;  // C
        for (unsigned i = 0U; i < 256U; ++i) { // C
            if ((i % 64U) == 0U) ref = (ref < 50.05F) ? 49.95F : 50.05F; // C
            adjust(b, ref);
            if ((i % (kNodes / 2U)) == 0U) {
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
