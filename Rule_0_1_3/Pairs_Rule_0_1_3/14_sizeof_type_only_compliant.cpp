// Title: Use the variable itself with sizeof(var) (Compliant per Rule 0-1-3)
// Seed example: 14_sizeof_trick (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <cstddef>

int main() {
    int n = 0;
    std::size_t s = sizeof n; // references the variable (unevaluated operand)
    std::cout << s << std::endl;
    // Rationale: All declared variables are referenced; compliant.
    return 0;
}