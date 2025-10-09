// Title: Template function arguments with lower-case suffix — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 08_08_hex_unsigned_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>

template <typename T>
T mul(T a, T b) { return a * b; }

int main() {
    std::cout << mul(2U, 3U) << "\n"; // upper-case 'U' arguments
    return 0;
}
