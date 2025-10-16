// Seed 026 (Compliant)
// Context: Filesystem — log rotation thresholds and units.
// Seed: Non-compliant: const unsigned limit = 10u;   // Compliant: const unsigned limit = 10U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const unsigned limit = 10U; // compliant
    std::cout << limit << "\n";
    return 0;
}