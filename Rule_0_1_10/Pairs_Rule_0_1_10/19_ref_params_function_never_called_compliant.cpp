// Title: Reference-parameter function is called (Compliant — Rule 0-1-10)
// Seed source: 19 (ref params) — corrected
#include <iostream>

void swap2(int& a, int& b) { int t = a; a = b; b = t; }

int main() {
    int x = 1, y = 2;
    swap2(x, y); // actual invocation
    std::cout << x + y << std::endl;
    // Rationale: swap2 is defined and invoked; compliant.
    return 0;
}
