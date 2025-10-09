// Title: do-while loop uses lower-case suffix literal — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 09_09_octal_suffix_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int i = 0U; // upper-case
    do {
        ++i;
    } while (i < 2U); // upper-case
    std::cout << i << "\n";
    return 0;
}
