// Title: Function returns literal with lower-case suffix — Compliant (MISRA C++:2008 Rule 2-13-4: literal suffixes shall be UPPER CASE)
// Seed reference: 06_06_sci_float_compliant.cpp (from /mnt/data/Seed_Rule_2-13-4.zip)
// Rationale: Literal suffixes corrected to upper case (e.g., 'U', 'L', 'F'), satisfying Rule 2-13-4.

#include <iostream>
static unsigned long capacity() {
    return 256UL; // compliant
}
int main() {
    std::cout << capacity() << "\n";
    return 0;
}
