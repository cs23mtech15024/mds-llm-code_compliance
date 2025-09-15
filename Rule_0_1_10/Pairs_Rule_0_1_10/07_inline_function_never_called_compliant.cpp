// Title: Inline function is called (Compliant — Rule 0-1-10)
// Seed source: 07 (inline) — corrected
#include <iostream>

inline int triple(int v) { return v * 3; }

int main() {
    std::cout << triple(4) << std::endl; // actual call
    // Rationale: 'triple' is defined and invoked; compliant.
    return 0;
}
