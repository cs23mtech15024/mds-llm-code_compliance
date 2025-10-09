// Title: Hex unsigned long with lower-case 'ul' — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 02_02_unsigned_decimal_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned long mask = 0xABCFUL; // UPPER-CASE 'UL'
    std::cout << mask << "\n";
    return 0;
}
