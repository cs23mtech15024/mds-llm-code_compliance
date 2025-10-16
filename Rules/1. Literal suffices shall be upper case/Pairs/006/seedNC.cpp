// Context: Physics simulation constants (gravity, time step) use lowercase 'f' suffix for float literals.
// Seed: Non-compliant: const float gravity = 9.81f;   // Compliant: const float gravity = 9.81F;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Violation: Uses lowercase ‘f’ suffix on floating-point literals.

#include <iostream>

int main() {
    const float gravity = 9.81f; // NC
    const float dt = 0.016f;     // NC

    float velocity = 0.0f;       // NC
    velocity += gravity * dt;

    std::cout << "Velocity after 1 frame: " << velocity << " m/s\n";
    return 0;
}