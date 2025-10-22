// Seed 013 (Non-Compliant)
// Context: PWM duty cycle calculation using fractional constants.
// Seed: Non-compliant: float duty = 0.25f;   // Compliant: float duty = 0.25F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase ‘f’ suffix on floating constant violates rule.

#include <iostream>

int main() {
    float duty = 0.25f; // non-compliant
    std::cout << "Initial duty cycle: " << duty * 100.0f << "%\n";
    return 0;
}