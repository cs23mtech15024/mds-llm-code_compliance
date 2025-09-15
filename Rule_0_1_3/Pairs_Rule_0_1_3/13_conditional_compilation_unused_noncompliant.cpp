// Title: Conditional compilation leaves variable unused in some builds (Non-compliant per Rule 0-1-3)
// Seed example: 13_conditional_compilation_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
#ifdef FEATURE_DEBUG
    int debug_level = 2; // Might be UNUSED when FEATURE_DEBUG is undefined later
#endif
    std::cout << "run" << std::endl;
    // Rationale: 'debug_level' may be unused in certain configurations; violates Rule 0-1-3.
    return 0;
}