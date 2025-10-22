// seed_001_nc_seed.cpp
// Seed: Non-compliant: float opacity = 0.43f;   // Compliant: float opacity = 0.43F
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper case.
// Violation: uses lowercase 'f' suffix.

#include <iostream>

int main() {
    float opacity = 0.43f; // non-compliant suffix
    std::cout << "opacity=" << opacity << "\n";
    return 0;
}