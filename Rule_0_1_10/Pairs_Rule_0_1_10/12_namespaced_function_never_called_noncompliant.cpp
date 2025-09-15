// Title: Namespaced function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 06_placeholder_never_called.cpp
#include <iostream>

namespace cfg {
    void reload() { std::cout << "reload\n"; } // defined, NEVER called
}

int main() {
    std::cout << "cfg" << std::endl;
    // Rationale: cfg::reload is defined but never invoked; non-compliant.
    return 0;
}
