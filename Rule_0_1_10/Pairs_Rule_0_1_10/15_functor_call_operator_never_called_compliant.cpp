// Title: Functor operator() is called (Compliant — Rule 0-1-10)
// Seed source: 15 (functor) — corrected
#include <iostream>

struct Times {
    int operator()(int a, int b) const { return a * b; }
};

int main() {
    Times t;
    std::cout << t(3, 4) << std::endl; // actual invocation
    // Rationale: operator() is called at least once; compliant.
    return 0;
}
