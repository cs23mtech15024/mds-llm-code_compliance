// Title: Default parameter uses lower-case suffix literal — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 10_10_mixed_case_suffix_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>

void logn(const char* s, unsigned int level = 1U) { // upper-case default
    std::cout << level << ":" << s << "\n";
}

int main() {
    logn("x");
    return 0;
}
