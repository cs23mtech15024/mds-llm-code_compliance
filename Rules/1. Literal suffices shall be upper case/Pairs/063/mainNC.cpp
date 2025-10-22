// Context: Autonomous car steering angle compensator

// ------ Non-Compliant Program (063_nc.cpp)
// Context: Autonomous car steering angle compensator
// Rule: MISRA C++ 2-13-4
// Violation: uses 0.9f, 100u, 3l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_063 {
    constexpr float    steeringGain = 0.9f;  // NC
    constexpr unsigned iterations   = 100u;  // NC
    constexpr long     bias         = 3l;    // NC

    struct State { float theta; float rate; };

    float ctrl(float err, float rate) {
        return 1.2f * err - 0.05f * rate + static_cast<float>(bias); // NC
    }

    void run() {
        State s{0.0f, 0.0f}; // NC
        for (unsigned i = 0u; i < iterations; ++i) {
            float ref = 0.2f * std::cos(0.03f * static_cast<float>(i)); // NC
            float e = ref - s.theta;
            float u = ctrl(e, s.rate);
            s.rate  += steeringGain * u * 0.01f; // NC
            s.theta += s.rate * 0.01f;           // NC
            if ((i % 20u) == 0u)
                std::cout << "[063] i=" << i << " th=" << std::fixed
                          << std::setprecision(3) << s.theta << " rt=" << s.rate << "\n";
        }
    }
}

int main(){ app_063::run(); return 0; }
