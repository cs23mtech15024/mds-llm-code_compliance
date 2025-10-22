// Context: Engine fuel injector timing calculator

// ------ Compliant Program (058_c.cpp)
// Seed 58 — Context: Engine fuel injector timing calculator
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 0.005F, 6000U, 11L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_058 {
    constexpr float    injectorDelay = 0.005F; // C (s)
    constexpr unsigned rpm           = 6000U;  // C
    constexpr long     baseTime      = 11L;    // C (ms)

    float cyclePeriod() {
        return 60.0F / static_cast<float>(rpm); // C
    }

    void run() {
        float T = cyclePeriod();
        float crankDegPerSec = 360.0F / T; // C
        float opening = (injectorDelay * crankDegPerSec) + static_cast<float>(baseTime);
        std::cout << "[058] T=" << std::fixed << std::setprecision(6) << T
                  << " open_deg=" << opening << "\n";
    }
}

int main() {
    app_058::run();
    return 0;
}