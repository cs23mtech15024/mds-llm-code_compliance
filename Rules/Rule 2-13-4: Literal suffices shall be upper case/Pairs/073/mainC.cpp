// Context: Nuclear reactor coolant pump ramp controller

// ------ Compliant Program (073_c.cpp)
// Context: Nuclear reactor coolant pump ramp controller
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Fix: uses 0.04F, 10U, 3001L

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_073 {
    constexpr float    ramp  = 0.04F; // C
    constexpr unsigned stages = 10U;  // C
    constexpr long     tag    = 3001L;// C

    float rampCmd(float step) {
        return step * ramp + static_cast<float>(tag);
    }

    void simulate() {
        for (unsigned s = 0U; s < stages; ++s) {
            float cmd = rampCmd(static_cast<float>(s));
            std::cout << "[073] Stage=" << s << " Cmd=" << std::fixed << std::setprecision(2)
                      << cmd << "\n";
        }
    }
}

int main(){ app_073::simulate(); return 0; }
