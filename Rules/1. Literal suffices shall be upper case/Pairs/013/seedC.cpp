// Seed 013 (Compliant)
// Context: PWM duty cycle calculation using fractional constants.
// Seed: Non-compliant: float duty = 0.25f;   // Compliant: float duty = 0.25F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    float duty = 0.25F; // compliant
    std::cout << "Initial duty cycle: " << duty * 100.0F << "%\n";
    return 0;
}