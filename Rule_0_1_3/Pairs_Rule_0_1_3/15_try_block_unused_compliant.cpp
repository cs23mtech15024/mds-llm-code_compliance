// Title: Variable inside try block is used (Compliant per Rule 0-1-3)
// Seed example: 15_try_catch_block_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int attempts = 0;
        ++attempts; // USE
        throw std::runtime_error("x");
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    // Rationale: All variables are referenced; compliant with Rule 0-1-3.
    return 0;
}