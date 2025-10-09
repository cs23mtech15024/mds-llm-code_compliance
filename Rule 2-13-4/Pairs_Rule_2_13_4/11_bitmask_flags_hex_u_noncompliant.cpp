// Title: Bitmask flags using 0x..u lower-case — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 06_06_sci_float_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int READ = 0x1u;   // lower-case
    unsigned int WRITE = 0x2u;  // lower-case
    unsigned int perm = READ | WRITE;
    std::cout << perm << "\n";
    return 0;
}
