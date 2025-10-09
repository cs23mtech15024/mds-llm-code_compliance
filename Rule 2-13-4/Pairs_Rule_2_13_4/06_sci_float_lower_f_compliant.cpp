// Title: Scientific notation float with lower-case 'f' — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 03_03_unsigned_long_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    float t = 1e3F; // UPPER-CASE 'F'
    std::cout << t << "\n";
    return 0;
}
