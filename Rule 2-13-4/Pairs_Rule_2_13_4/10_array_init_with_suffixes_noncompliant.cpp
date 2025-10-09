// Title: Array initializers with lower-case literal suffixes — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 05_05_float_literal_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
int main() {
    unsigned int arr[3] = { 1u, 2u, 3u }; // lower-case 'u'
    unsigned long sum = arr[0] + arr[1] + arr[2];
    std::cout << sum << "\n";
    return 0;
}
