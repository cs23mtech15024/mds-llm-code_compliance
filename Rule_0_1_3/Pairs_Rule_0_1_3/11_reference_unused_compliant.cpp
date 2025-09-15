// Title: Reference is read and written (Compliant per Rule 0-1-3)
// Seed example: 11_reference_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int x = 5;
    int& r = x;
    r += 3; // write via reference
    std::cout << "x=" << r << std::endl; // read via reference
    // Rationale: All declared variables (including the reference) are used — compliant.
    return 0;
}