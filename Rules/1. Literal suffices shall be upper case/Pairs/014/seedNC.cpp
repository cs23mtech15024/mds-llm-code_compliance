// Seed 014 (Non-Compliant)
// Context: Physics simulation — basic gravitational velocity calculation.
// Seed: Non-compliant: const float g = 9.81f;   // Compliant: const float g = 9.81F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Use of lower-case 'f' on floating-point literal.

#include <iostream>

int main() {
    const float g = 9.81f;  // non-compliant
    float time = 2.0f;
    float velocity = g * time;
    std::cout << "Velocity after " << time << "s = " << velocity << " m/s\n";
    return 0;
}