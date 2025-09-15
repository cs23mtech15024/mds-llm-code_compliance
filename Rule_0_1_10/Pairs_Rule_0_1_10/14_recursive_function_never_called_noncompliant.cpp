// Title: Recursive function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 07_placeholder_never_called.cpp
#include <iostream>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; } // defined, NEVER called

int main() {
    std::cout << "math" << std::endl;
    // Rationale: gcd is never invoked; non-compliant.
    return 0;
}
