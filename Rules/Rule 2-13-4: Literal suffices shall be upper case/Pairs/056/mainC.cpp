// Context: Nuclear reactor coolant flow rate monitor

// ------ Compliant Program (056_c.cpp)
// Seed 56 — Context: Nuclear reactor coolant flow rate monitor
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: uses 5.5F, 60U, 77L (uppercase suffixes)

#include <iostream>
#include <iomanip>
#include <deque>

namespace app_056 {
    constexpr float    flowRate  = 5.5F; // C (L/s per unit signal)
    constexpr unsigned cycleTime = 60U;  // C (s)
    constexpr long     alertCode = 77L;  // C

    float sample(unsigned t) {
        // Synthetic sensor signal with small ripple
        return 10.0F + 0.5F * std::sin(0.05F * static_cast<float>(t)); // C
    }

    void run() {
        std::deque<float> window;
        float acc = 0.0F; // C
        for (unsigned t = 0U; t < 600U; ++t) { // C
            float s = sample(t);
            float flow = s * flowRate;
            window.push_back(flow);
            acc += flow;
            if (window.size() > cycleTime) { acc -= window.front(); window.pop_front(); }
            if (t % 120U == 0U) { // C
                float avg = acc / static_cast<float>(window.size());
                std::cout << "[056] t=" << t << " flow(avg)=" << std::fixed
                          << std::setprecision(2) << avg << " alert=" << alertCode << "\n";
            }
        }
    }
}

int main() {
    app_056::run();
    return 0;
}
