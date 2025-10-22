// Seed 015 (Non-Compliant)
// Context: Robotics PID — literal suffixes in tuning constants.
// Seed: Non-compliant: const unsigned long integralCap = 1000ul;   // Compliant: const unsigned long integralCap = 1000UL
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lower-case 'ul' on an integer literal.

#include <iostream>

int main() {
    const unsigned long integralCap = 1000ul; // non-compliant
    std::cout << "Integral cap = " << integralCap << "\n";
    return 0;
}