// Seed 038 (Compliant)
// Context: Embedded Systems — PWM duty cycle computation for motor control.
// Seed: Non-compliant: const float kDutyMin = 0.05f; const float kDutyMax = 0.95f; const unsigned kPwmMask = 0xffu; const long kTicksPerCycle = 1000l;
//        Compliant:     const float kDutyMin = 0.05F; const float kDutyMax = 0.95F; const unsigned kPwmMask = 0XFFU; const long kTicksPerCycle = 1000L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float kDutyMin = 0.05F;      // compliant
    const float kDutyMax = 0.95F;      // compliant
    const unsigned kPwmMask = 0XFFU;   // compliant
    const long kTicksPerCycle = 1000L; // compliant

    std::cout << kDutyMin << " " << kDutyMax << " "
              << kPwmMask << " " << kTicksPerCycle << "\n";
    return 0;
}