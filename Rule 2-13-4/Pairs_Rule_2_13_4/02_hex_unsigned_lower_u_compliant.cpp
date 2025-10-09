// Title: Hex unsigned with lower-case 'u' — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 01_01_decimal_long_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int mask = 0xFFU; // UPPER-CASE 'U' and hex digits
    std::cout << mask << "\n";
    return 0;
}
