// Title: Function suitable for function pointer never called (Non-compliant — Rule 0-1-10)
// Seed source: 07_inline_function_never_called.cpp
#include <iostream>

int to_even(int v) { return (v % 2) ? v+1 : v; } // defined, NEVER called

int main() {
    std::cout << "x" << std::endl;
    // Rationale: to_even is never invoked (address not enough); non-compliant.
    return 0;
}
