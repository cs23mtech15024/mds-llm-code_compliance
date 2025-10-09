// Title: Mixed expressions containing multiple lower-case suffixes — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 04_04_unsigned_long_long_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned long a = 5ul; // non-compliant
    unsigned int  b = 2u;  // non-compliant
    float         c = 1.0f; // non-compliant
    std::cout << (a + b) * c << "\n";
    return 0;
}
