// Title: Struct member initialization with lower-case suffix — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 07_07_long_double_noncompliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>

struct Limits {
    unsigned long cap;
    float factor;
};

int main() {
    Limits L = { 512ul, 0.25f }; // lower-case suffixes
    std::cout << L.cap << " " << L.factor << "\n";
    return 0;
}
