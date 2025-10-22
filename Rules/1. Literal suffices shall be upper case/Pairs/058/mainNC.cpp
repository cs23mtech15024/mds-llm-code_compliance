// Context: Engine fuel injector timing calculator

// ------ Non-Compliant Program (058_nc.cpp)
// Seed 58 — Context: Engine fuel injector timing calculator
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 0.005f, 6000u, 11l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_058 {
    constexpr float    injectorDelay = 0.005f; // NC (s)
    constexpr unsigned rpm           = 6000u;  // NC
    constexpr long     baseTime      = 11l;    // NC (ms)

    float cyclePeriod() {
        return 60.0f / static_cast<float>(rpm); // NC
    }

    void run() {
        float T = cyclePeriod();
        float crankDegPerSec = 360.0f / T; // NC
        float opening = (injectorDelay * crankDegPerSec) + static_cast<float>(baseTime);
        std::cout << "[058] T=" << std::fixed << std::setprecision(6) << T
                  << " open_deg=" << opening << "\n";
    }
}

int main() {
    app_058::run();
    return 0;
}
