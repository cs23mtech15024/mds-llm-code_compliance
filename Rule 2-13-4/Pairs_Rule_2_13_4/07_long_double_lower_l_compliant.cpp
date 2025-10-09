// Title: Long double with lower-case 'l' suffix — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 04_04_unsigned_long_long_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    long double z = 2.0L; // UPPER-CASE 'L'
    std::cout << z << "\n";
    return 0;
}
