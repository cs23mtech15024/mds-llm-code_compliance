// Title: Switch cases comparing against lower-case suffix literals — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 07_07_long_double_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int code = 2U; // upper-case
    switch (code) {
        case 1U: std::cout << "one\n"; break; // upper-case
        case 2U: std::cout << "two\n"; break; // upper-case
        default: std::cout << "other\n"; break;
    }
    return 0;
}
