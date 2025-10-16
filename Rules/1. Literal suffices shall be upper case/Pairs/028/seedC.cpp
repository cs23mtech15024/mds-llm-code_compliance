// Seed 028 (Compliant)
// Context: Graphics — pixel shader constants for brightness scaling.
// Seed: Non-compliant: const float intensity = 0.75f;   // Compliant: const float intensity = 0.75F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float intensity = 0.75F; // compliant
    std::cout << intensity << "\n";
    return 0;
}