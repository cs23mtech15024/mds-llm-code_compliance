// Title: do-while loop uses lower-case suffix literal — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 09_09_octal_suffix_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int i = 0u; // lower-case
    do {
        ++i;
    } while (i < 2u); // lower-case
    std::cout << i << "\n";
    return 0;
}
