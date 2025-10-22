// Seed 018 (Non-Compliant)
// Context: Embedded sensor fusion (Kalman filter tuning constants)
// Seed: Non-compliant: const float processNoise = 1e-3f;   // Compliant: const float processNoise = 1e-3F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' suffix in scientific literal.

#include <iostream>

int main() {
    const float processNoise = 1e-3f; // non-compliant
    std::cout << "Process noise: " << processNoise << "\n";
    return 0;
}