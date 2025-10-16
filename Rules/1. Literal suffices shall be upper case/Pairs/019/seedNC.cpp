// Seed 019 (Non-Compliant)
// Context: Computer Vision — histogram equalization constants (max value, epsilon)
// Seed: Non-compliant: const unsigned maxVal = 255u;   // Compliant: const unsigned maxVal = 255U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'u' suffix for an unsigned integer literal.

#include <iostream>

int main() {
    const unsigned maxVal = 255u; // non-compliant
    std::cout << maxVal << "\n";
    return 0;
}