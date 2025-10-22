// Seed 020 (Non-Compliant)
// Context: Robotics — PID timestep constant for control loop.
// Seed: Non-compliant: const float dt = 0.001f;   // Compliant: const float dt = 0.001F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' suffix for a floating literal.

#include <iostream>

int main() {
    const float dt = 0.001f; // non-compliant
    std::cout << dt << "\n";
    return 0;
}