// Seed 045 (Non-Compliant)
// Context: Battery Charge Simulation — Voltage Factor, Step Count, and Initial Charge
// Seed: Non-compliant: const float kVoltageStep = 0.5f; const unsigned kSteps = 10u; const long kInitialCharge = 100l;
//         Compliant:    const float kVoltageStep = 0.5F; const unsigned kSteps = 10U; const long kInitialCharge = 100L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase suffixes 'f', 'u', and 'l' used in literals.

#include <iostream>

int main() {
    const float kVoltageStep = 0.5f;   // non-compliant
    const unsigned kSteps = 10u;       // non-compliant
    const long kInitialCharge = 100l;  // non-compliant
    std::cout << kVoltageStep << " " << kSteps << " " << kInitialCharge << "\n";
    return 0;
}