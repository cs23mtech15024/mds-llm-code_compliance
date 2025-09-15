// Title: Remove extra variable or use it (Compliant per Rule 0-1-3)
// Seed example: 19_for_init_list_extra_var (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    for (int i = 0; i < 4; ++i) {
        std::cout << i << std::endl;
    }
    // Rationale: No extraneous variable exists in the for-init; all variables are used — compliant.
    return 0;
}