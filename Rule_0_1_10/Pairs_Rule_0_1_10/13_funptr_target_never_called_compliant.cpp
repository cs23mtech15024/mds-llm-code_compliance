// Title: Function is actually called (Compliant — Rule 0-1-10)
// Seed source: 13 (function pointer target) — corrected
#include <iostream>

int to_even(int v) { return (v % 2) ? v+1 : v; }

int main() {
    int (*fp)(int) = &to_even; // taking address is fine but not sufficient
    std::cout << fp(7) << std::endl;  // actual invocation via pointer
    // Rationale: Defined function is invoked at least once; compliant.
    return 0;
}
