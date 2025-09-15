// Title: Function-scope static variable never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 02_local_static_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

static void step() {
    static int s_counter = 0; // UNUSED (violates Rule 0-1-3)
    // Work that doesn't use s_counter:
    std::cout << ".";
}

int main() {
    for (int i = 0; i < 10; ++i) {
        step();
    }
    std::cout << std::endl;
    // Rationale: 's_counter' is declared and never read or written after declaration; this unused
    // variable violates Rule 0-1-3.
    return 0;
}