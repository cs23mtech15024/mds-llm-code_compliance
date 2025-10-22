// Seed 024 (Non-Compliant)
// Context: Embedded PWM — base duty and timer period.
// Seed: Non-compliant: const float duty = 0.50f;   // Compliant: const float duty = 0.50F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' suffix for a floating literal.

#include <iostream>

int main() {
    const float duty = 0.50f; // non-compliant
    std::cout << duty << "\n";
    return 0;
}