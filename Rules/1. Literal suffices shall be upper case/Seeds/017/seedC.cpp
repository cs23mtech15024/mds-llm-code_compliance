// Seed 017 (Compliant)
// Context: Robotics PID and encoder scaling — literals use uppercase suffixes.
// Seed: Non-compliant: const long TICKS_PER_REV = 2048l; // Compliant: const long TICKS_PER_REV = 2048L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const long TICKS_PER_REV = 2048L; // compliant
    std::cout << TICKS_PER_REV << "\n";
    return 0;
}