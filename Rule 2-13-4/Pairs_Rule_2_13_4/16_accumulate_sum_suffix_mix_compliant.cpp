// Title: Loop accumulation using lower-case suffix literals — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 08_08_hex_unsigned_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>

int main() {
    unsigned long sum = 0UL; // upper-case
    for (unsigned int i = 0U; i < 5U; ++i) { // upper-case
        sum += i + 1U; // upper-case
    }
    std::cout << sum << "\n";
    return 0;
}
