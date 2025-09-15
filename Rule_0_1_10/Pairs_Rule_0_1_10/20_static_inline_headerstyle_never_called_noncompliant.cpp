// Title: static inline utility defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 10_placeholder_never_called.cpp
#include <iostream>

static inline void banner(const char* s) { std::cout << "[ " << s << " ]\n"; } // NEVER called

int main() {
    std::cout << "done" << std::endl;
    // Rationale: banner is defined but not invoked; non-compliant.
    return 0;
}
