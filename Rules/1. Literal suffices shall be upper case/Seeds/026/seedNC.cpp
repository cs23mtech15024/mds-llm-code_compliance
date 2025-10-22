// Seed 026 (Non-Compliant)
// Context: Filesystem — log rotation thresholds and units.
// Seed: Non-compliant: const unsigned limit = 10u;   // Compliant: const unsigned limit = 10U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'u' suffix for an unsigned literal.

#include <iostream>

int main() {
    const unsigned limit = 10u; // non-compliant
    std::cout << limit << "\n";
    return 0;
}