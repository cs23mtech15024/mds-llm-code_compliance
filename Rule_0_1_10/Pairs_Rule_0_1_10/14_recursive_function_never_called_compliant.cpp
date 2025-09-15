// Title: Recursive function is invoked (Compliant — Rule 0-1-10)
// Seed source: 14 (recursive) — corrected
#include <iostream>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    std::cout << gcd(12, 18) << std::endl; // actual call
    // Rationale: The defined recursive function is called at least once; compliant.
    return 0;
}
