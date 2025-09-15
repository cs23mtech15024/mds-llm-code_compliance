// Title: volatile variable is read into a snapshot (Compliant per Rule 0-1-3)
// Seed example: 18_volatile_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    volatile int status = 0;
    int snapshot = status; // read (use) volatile
    std::cout << "snapshot=" << snapshot << std::endl;
    // Rationale: All declared variables are referenced; compliant.
    return 0;
}