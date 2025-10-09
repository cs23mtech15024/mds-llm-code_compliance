// Title: Macro-defined literal with lower-case suffix — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 05_05_float_literal_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
#define MAX_ITEMS 128u   // lower-case suffix in macro

int main() {
    unsigned int lim = MAX_ITEMS;
    std::cout << lim << "\n";
    return 0;
}
