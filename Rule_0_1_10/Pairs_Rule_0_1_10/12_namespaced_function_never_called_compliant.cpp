// Title: Namespaced function is called (Compliant — Rule 0-1-10)
// Seed source: 12 (namespace) — corrected
#include <iostream>

namespace cfg {
    void reload() { std::cout << "reload\n"; }
}

int main() {
    cfg::reload(); // actual call
    std::cout << "cfg" << std::endl;
    // Rationale: cfg::reload is defined and invoked; compliant.
    return 0;
}
