// Title: Block-scoped variable inside switch is never used (Non-compliant per Rule 0-1-3)
// Seed example: 10_switch_block_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int code = 2;
    switch (code) {
        case 1: {
            int temp; // UNUSED (violates Rule 0-1-3)
            std::cout << "one" << std::endl;
            break;
        }
        case 2: {
            std::cout << "two" << std::endl;
            break;
        }
        default: {
            std::cout << "other" << std::endl;
            break;
        }
    }
    // Rationale: 'temp' is declared and never referenced; unused variable.
    return 0;
}