// Title: Unused const char* debug string (Non-compliant per Rule 0-1-3)
// Seed example: 20_local_const_charptr_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    const char* debug = "TRACE: enter main"; // UNUSED (violates Rule 0-1-3)
    std::cout << "running" << std::endl;
    // Rationale: 'debug' is declared but never referenced; unused variable.
    return 0;
}