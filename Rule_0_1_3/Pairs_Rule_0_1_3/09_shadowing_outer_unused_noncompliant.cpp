// Title: Shadowing causes outer variable to be unused (Non-compliant per Rule 0-1-3)
// Seed example: 09_shadowing_hides_use (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int count = 1; // OUTER and UNUSED (violates Rule 0-1-3)
    {
        int count = 2; // shadows outer
        std::cout << "inner=" << count << std::endl;
    }
    // Outer 'count' was never referenced.
    // Rationale: The outer variable is declared but never used; violates Rule 0-1-3.
    return 0;
}