// Context: Nuclear reactor coolant flow rate monitor

// ------ Non-Compliant Program (056_nc.cpp)
// Seed 56 — Context: Nuclear reactor coolant flow rate monitor
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: uses 5.5f, 60u, 77l (lowercase suffixes)

#include <iostream>
#include <iomanip>
#include <deque>

namespace app_056 {
    constexpr float    flowRate  = 5.5f; // NC (L/s per unit signal)
    constexpr unsigned cycleTime = 60u;  // NC (s)
    constexpr long     alertCode = 77l;  // NC

    float sample(unsigned t) {
        // Synthetic sensor signal with small ripple
        return 10.0f + 0.5f * std::sin(0.05f * static_cast<float>(t)); // NC
    }

    void run() {
        std::deque<float> window;
        float acc = 0.0f; // NC
        for (unsigned t = 0u; t < 600u; ++t) { // NC
            float s = sample(t);
            float flow = s * flowRate;
            window.push_back(flow);
            acc += flow;
            if (window.size() > cycleTime) { acc -= window.front(); window.pop_front(); }
            if (t % 120u == 0u) { // NC
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
