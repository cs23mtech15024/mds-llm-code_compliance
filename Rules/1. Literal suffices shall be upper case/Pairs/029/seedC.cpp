// Seed 029 (Compliant)
// Context: Robotics — PID controller gains used in a motor speed loop.
// Seed: Non-compliant: const float Kp = 0.8f; const unsigned window = 100u;   // Compliant: const float Kp = 0.8F; const unsigned window = 100U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float Kp = 0.8F;       // compliant
    const unsigned window = 100U; // compliant
    std::cout << Kp << " " << window << "\n";
    return 0;
}