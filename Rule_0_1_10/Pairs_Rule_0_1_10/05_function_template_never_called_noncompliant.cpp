// Title: Function template defined but never instantiated/called (Non-compliant — Rule 0-1-10)
// Seed source: 03_member_function_never_called.cpp
#include <iostream>

template <typename T>
T clamp01(T v) { return (v < 0 ? 0 : (v > 1 ? 1 : v)); } // defined, NEVER called

int main() {
    std::cout << "ok" << std::endl;
    // Rationale: Template is never instantiated by a call; non-compliant.
    return 0;
}
