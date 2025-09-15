// Title: Extra variable in for-init list is never used (Non-compliant per Rule 0-1-3)
// Seed example: 19_for_init_list_extra_var (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    for (int i = 0, j = 0; i < 4; ++i) { // 'j' is UNUSED (violates Rule 0-1-3)
        std::cout << i << std::endl;
    }
    // Rationale: Variable 'j' is never referenced; unused variable.
    return 0;
}