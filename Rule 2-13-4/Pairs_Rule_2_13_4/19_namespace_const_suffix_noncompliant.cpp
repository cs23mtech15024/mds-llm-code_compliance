// Title: Namespace-scope const with lower-case suffix — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 10_10_mixed_case_suffix_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>

namespace cfg {
    const unsigned long Size = 64ul; // lower-case
}

int main() {
    std::cout << cfg::Size << "\n";
    return 0;
}
