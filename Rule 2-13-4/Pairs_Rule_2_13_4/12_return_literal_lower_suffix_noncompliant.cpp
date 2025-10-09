// Title: Function returns literal with lower-case suffix — Non-compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 06_06_sci_float_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Uses lower-case literal suffix(es) (e.g., 'u', 'l', 'f'); violates Rule 2-13-4.

#include <iostream>
static unsigned long capacity() {
    return 256ul; // non-compliant
}
int main() {
    std::cout << capacity() << "\n";
    return 0;
}
