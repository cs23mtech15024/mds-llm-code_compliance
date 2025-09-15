// Title: Inline function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 04_placeholder_never_called.cpp
#include <iostream>

inline int triple(int v) { return v * 3; } // defined, NEVER called

int main() {
    std::cout << "ready" << std::endl;
    // Rationale: 'triple' is never invoked; non-compliant.
    return 0;
}
