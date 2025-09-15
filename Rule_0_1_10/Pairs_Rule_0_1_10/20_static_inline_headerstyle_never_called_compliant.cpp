// Title: static inline utility is called (Compliant — Rule 0-1-10)
// Seed source: 20 (static inline) — corrected
#include <iostream>

static inline void banner(const char* s) { std::cout << "[ " << s << " ]\n"; }

int main() {
    banner("start"); // actual invocation
    std::cout << "done" << std::endl;
    // Rationale: banner is defined and invoked; compliant.
    return 0;
}
