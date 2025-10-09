// Title: Template function arguments with lower-case suffix — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 08_08_hex_unsigned_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>

template <typename T>
T mul(T a, T b) { return a * b; }

int main() {
    std::cout << mul(2u, 3u) << "\n"; // lower-case 'u' arguments
    return 0;
}
