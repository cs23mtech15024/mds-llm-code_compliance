// Context: Nuclear reactor coolant pump ramp controller

// ------ Non-Compliant Program (073_nc.cpp)
// Context: Nuclear reactor coolant pump ramp controller
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper-case.
// Violation: uses 0.04f, 10u, 3001l

#include <iostream>
#include <iomanip>
#include <cmath>

namespace app_073 {
    constexpr float    ramp  = 0.04f; // NC
    constexpr unsigned stages = 10u;  // NC
    constexpr long     tag    = 3001l;// NC

    float rampCmd(float step) {
        return step * ramp + static_cast<float>(tag);
    }

    void simulate() {
        for (unsigned s = 0u; s < stages; ++s) {
            float cmd = rampCmd(static_cast<float>(s));
            std::cout << "[073] Stage=" << s << " Cmd=" << std::fixed << std::setprecision(2)
                      << cmd << "\n";
        }
    }
}

int main(){ app_073::simulate(); return 0; }
