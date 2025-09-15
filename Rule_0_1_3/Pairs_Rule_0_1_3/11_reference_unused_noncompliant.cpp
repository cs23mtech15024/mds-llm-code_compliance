// Title: Reference bound but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 11_reference_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int x = 5;
    int& r = x; // UNUSED (violates Rule 0-1-3)
    std::cout << "start" << std::endl;
    // Rationale: 'r' is never read or written; unused variable.
    return 0;
}