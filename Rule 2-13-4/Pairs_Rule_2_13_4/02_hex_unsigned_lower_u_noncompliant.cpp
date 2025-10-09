// Title: Hex unsigned with lower-case 'u' — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 01_01_decimal_long_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int mask = 0xffu; // lower-case 'u' and hex
    std::cout << mask << "\n";
    return 0;
}
