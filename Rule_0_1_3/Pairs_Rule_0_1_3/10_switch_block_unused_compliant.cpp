// Title: Block-scoped variable inside switch is used (Compliant per Rule 0-1-3)
// Seed example: 10_switch_block_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int code = 1;
    switch (code) {
        case 1: {
            int temp = 7; // USED
            std::cout << "one+" << temp << std::endl;
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
    // Rationale: All variables declared in blocks are referenced — compliant.
    return 0;
}