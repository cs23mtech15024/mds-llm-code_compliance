// Title: volatile variable declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 18_volatile_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    volatile int status = 0; // UNUSED (violates Rule 0-1-3)
    std::cout << "init" << std::endl;
    // Rationale: Even volatile variables must be referenced; otherwise unused.
    return 0;
}