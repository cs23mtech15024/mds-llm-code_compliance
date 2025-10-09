// Title: Switch cases comparing against lower-case suffix literals — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 07_07_long_double_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int code = 2u; // lower-case
    switch (code) {
        case 1u: std::cout << "one\n"; break; // lower-case
        case 2u: std::cout << "two\n"; break; // lower-case
        default: std::cout << "other\n"; break;
    }
    return 0;
}
