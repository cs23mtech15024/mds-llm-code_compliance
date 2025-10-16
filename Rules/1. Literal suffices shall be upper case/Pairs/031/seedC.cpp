// Seed 031 (Compliant)
// Context: Aerospace Navigation — GPS coordinate normalization constants for precision scaling.
// Seed: Non-compliant: const double DEG2RAD = 0.01745f; const unsigned MAX_POINTS = 1000u;   // Compliant: const double DEG2RAD = 0.01745F; const unsigned MAX_POINTS = 1000U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const double DEG2RAD = 0.01745F; // compliant
    const unsigned MAX_POINTS = 1000U; // compliant
    std::cout << DEG2RAD << " " << MAX_POINTS << "\n";
    return 0;
}