// Title: Bitmask flags using 0x..u lower-case — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 06_06_sci_float_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int READ = 0x1U;   // upper-case
    unsigned int WRITE = 0x2U;  // upper-case
    unsigned int perm = READ | WRITE;
    std::cout << perm << "\n";
    return 0;
}
