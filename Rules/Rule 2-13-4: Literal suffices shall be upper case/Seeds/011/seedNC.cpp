// Seed 011 (Non-Compliant)
// Context: Filesystem permission masks (octal) used in POSIX-style code.
// Seed: Non-compliant: const unsigned mode = 0644u;   // Compliant: const unsigned mode = 0644U
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case (e.g., U, L, UL).
// Violation: Uses lower-case integer suffix 'u' on an integer literal.

#include <iostream>

int main() {
    const unsigned mode = 0644u; // lower-case 'u' suffix: non-compliant
    std::cout << "Mode is: " << std::oct << mode << "\n";
    return 0;
}