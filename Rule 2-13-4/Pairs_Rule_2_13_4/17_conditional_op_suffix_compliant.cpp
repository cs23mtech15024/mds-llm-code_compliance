// Title: Ternary operator with lower-case suffix literals — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 09_09_octal_suffix_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int a = 0U;
    unsigned int b = (a == 0U) ? 10U : 20U; // upper-case
    std::cout << b << "\n";
    return 0;
}
