// Title: Enumeration variable declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 05_enum_var_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

enum State { Idle, Busy, Error };

int main() {
    State current; // UNUSED (violates Rule 0-1-3)
    std::cout << "system starting" << std::endl;
    // Rationale: 'current' is never read/written; unused variable violates Rule 0-1-3.
    return 0;
}