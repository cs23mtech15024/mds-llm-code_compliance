// Title: const char* is printed (Compliant per Rule 0-1-3)
// Seed example: 20_local_const_charptr_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    const char* debug = "TRACE: enter main";
    std::cout << debug << std::endl; // USE debug
    // Rationale: All declared variables are referenced; compliant.
    return 0;
}