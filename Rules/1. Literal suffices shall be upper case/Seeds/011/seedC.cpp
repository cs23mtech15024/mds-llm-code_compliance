// Seed 011 (Compliant)
// Context: Filesystem permission masks (octal) used in POSIX-style code.
// Seed: Non-compliant: const unsigned mode = 0644u;   // Compliant: const unsigned mode = 0644U
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case (e.g., U, L, UL).

#include <iostream>

int main() {
    const unsigned mode = 0644U; // upper-case 'U' suffix: compliant
    std::cout << "Mode is: " << std::oct << mode << "\n";
    return 0;
}