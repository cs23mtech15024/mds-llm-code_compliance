// Seed 029 (Non-Compliant)
// Context: Robotics — PID controller gains used in a motor speed loop.
// Seed: Non-compliant: const float Kp = 0.8f; const unsigned window = 100u;   // Compliant: const float Kp = 0.8F; const unsigned window = 100U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' and 'u' suffixes for literals.

#include <iostream>

int main() {
    const float Kp = 0.8f;      // non-compliant
    const unsigned window = 100u; // non-compliant
    std::cout << Kp << " " << window << "\n";
    return 0;
}