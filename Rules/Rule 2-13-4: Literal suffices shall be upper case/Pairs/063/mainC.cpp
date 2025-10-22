// Context: Autonomous car steering angle compensator

// ------ Compliant Program (063_c.cpp)
// Context: Autonomous car steering angle compensator
// Rule: MISRA C++ 2-13-4
// Fix: uses 0.9F, 100U, 3L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_063 {
    constexpr float    steeringGain = 0.9F;  // C
    constexpr unsigned iterations   = 100U;  // C
    constexpr long     bias         = 3L;    // C

    struct State { float theta; float rate; };

    float ctrl(float err, float rate) {
        return 1.2F * err - 0.05F * rate + static_cast<float>(bias); // C
    }

    void run() {
        State s{0.0F, 0.0F}; // C
        for (unsigned i = 0U; i < iterations; ++i) {
            float ref = 0.2F * std::cos(0.03F * static_cast<float>(i)); // C
            float e = ref - s.theta;
            float u = ctrl(e, s.rate);
            s.rate  += steeringGain * u * 0.01F; // C
            s.theta += s.rate * 0.01F;           // C
            if ((i % 20U) == 0U)
                std::cout << "[063] i=" << i << " th=" << std::fixed
                          << std::setprecision(3) << s.theta << " rt=" << s.rate << "\n";
        }
    }
}

int main(){ app_063::run(); return 0; }
