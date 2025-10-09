// Title: Ternary operator with lower-case suffix literals — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 09_09_octal_suffix_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int a = 0u;
    unsigned int b = (a == 0u) ? 10u : 20u; // lower-case
    std::cout << b << "\n";
    return 0;
}
