// Title: Loop accumulation using lower-case suffix literals — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 08_08_hex_unsigned_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>

int main() {
    unsigned long sum = 0ul; // lower-case
    for (unsigned int i = 0u; i < 5u; ++i) { // lower-case
        sum += i + 1u; // lower-case
    }
    std::cout << sum << "\n";
    return 0;
}
