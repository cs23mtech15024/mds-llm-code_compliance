// Title: Mixed expressions containing multiple lower-case suffixes — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 04_04_unsigned_long_long_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned long a = 5UL; // compliant
    unsigned int  b = 2U;  // compliant
    float         c = 1.0F; // compliant
    std::cout << (a + b) * c << "\n";
    return 0;
}
