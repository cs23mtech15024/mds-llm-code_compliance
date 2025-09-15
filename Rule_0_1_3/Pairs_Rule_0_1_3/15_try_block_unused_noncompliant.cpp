// Title: Variable inside try block never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 15_try_catch_block_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int attempts = 0; // UNUSED (violates Rule 0-1-3)
        throw std::runtime_error("x");
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    // Rationale: 'attempts' is declared but never used; unused variable.
    return 0;
}