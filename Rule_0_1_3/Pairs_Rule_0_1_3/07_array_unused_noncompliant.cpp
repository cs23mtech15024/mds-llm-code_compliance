// Title: Array declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 07_array_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int hist[10]; // UNUSED (violates Rule 0-1-3)
    for (int i = 0; i < 3; ++i) {
        std::cout << "tick" << std::endl;
    }
    // Rationale: 'hist' is never read or written; unused variable.
    return 0;
}