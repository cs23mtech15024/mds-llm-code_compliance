// Title: Float literal with lower-case 'f' — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 03_03_unsigned_long_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    float k = 3.5f; // lower-case 'f' (non-compliant)
    std::cout << k << "\n";
    return 0;
}
