// Title: Hex unsigned long with lower-case 'ul' — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 02_02_unsigned_decimal_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned long mask = 0xabcful; // lower-case 'ul'
    std::cout << mask << "\n";
    return 0;
}
