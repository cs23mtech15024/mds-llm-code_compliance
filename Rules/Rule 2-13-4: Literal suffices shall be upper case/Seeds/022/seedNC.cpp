// Seed 022 (Non-Compliant)
// Context: Filesystem — maximum retained log files.
// Seed: Non-compliant: const unsigned maxFiles = 7u;   // Compliant: const unsigned maxFiles = 7U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'u' suffix for an unsigned literal.

#include <iostream>

int main() {
    const unsigned maxFiles = 7u; // non-compliant
    std::cout << maxFiles << "\n";
    return 0;
}