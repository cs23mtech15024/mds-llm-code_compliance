// Title: Conditional compilation uses variable under the same condition (Compliant per Rule 0-1-3)
// Seed example: 13_conditional_compilation_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
#ifdef FEATURE_DEBUG
    int debug_level = 2; // USED consistently
    if (debug_level >= 2) {
        std::cout << "debug verbose" << std::endl;
    } else {
        std::cout << "debug basic" << std::endl;
    }
#else
    std::cout << "run" << std::endl;
#endif
    // Rationale: No configuration leaves a declared variable unused — compliant.
    return 0;
}