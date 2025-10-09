// Title: Default parameter uses lower-case suffix literal — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 10_10_mixed_case_suffix_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>

void logn(const char* s, unsigned int level = 1u) { // lower-case default
    std::cout << level << ":" << s << "\n";
}

int main() {
    logn("x");
    return 0;
}
