// Title: Enumeration variable participates in logic (Compliant per Rule 0-1-3)
// Seed example: 05_enum_var_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

enum State { Idle, Busy, Error };

int main() {
    State current = Busy;
    if (current == Busy) {
        std::cout << "system busy" << std::endl;
    } else {
        std::cout << "system not busy" << std::endl;
    }
    // Rationale: Every declared variable, including 'current', is referenced; compliant.
    return 0;
}