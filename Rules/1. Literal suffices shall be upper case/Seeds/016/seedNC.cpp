// Seed 016 (Non-Compliant)
// Context: Audio DSP gain normalization constants using float suffixes.
// Seed: Non-compliant: float gain = 1.5f;   // Compliant: float gain = 1.5F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: 'f' suffix used in lowercase on floating literals.

#include <iostream>

int main() {
    float gain = 1.5f;  // non-compliant
    std::cout << "Gain = " << gain << "\n";
    return 0;
}