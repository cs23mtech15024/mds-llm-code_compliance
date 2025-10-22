// Context: Physics simulation constants (gravity, time step) use uppercase 'F' suffix for float literals.
// Seed: Non-compliant: const float gravity = 9.81f;   // Compliant: const float gravity = 9.81F;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Fix: All float literals use uppercase ‘F’ suffix.

#include <iostream>

int main() {
    const float gravity = 9.81F; // C
    const float dt = 0.016F;     // C

    float velocity = 0.0F;       // C
    velocity += gravity * dt;

    std::cout << "Velocity after 1 frame: " << velocity << " m/s\n";
    return 0;
}