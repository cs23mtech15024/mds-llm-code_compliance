// Title: Declared variable but code uses sizeof(type) (Non-compliant per Rule 0-1-3)
// Seed example: 14_sizeof_trick (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <cstddef>

int main() {
    int n; // UNUSED (violates Rule 0-1-3)
    std::size_t s = sizeof(int); // does not reference 'n'
    std::cout << s << std::endl;
    // Rationale: 'n' is declared but not referenced; unused variable.
    return 0;
}