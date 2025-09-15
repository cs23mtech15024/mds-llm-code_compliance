// Title: Functor operator() defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 08_overload_one_unused.cpp
#include <iostream>

struct Times {
    int operator()(int a, int b) const { return a * b; } // defined, NEVER called
};

int main() {
    Times t; (void)t; // object exists but not invoked
    std::cout << "mul" << std::endl;
    // Rationale: operator() is never invoked; non-compliant.
    return 0;
}
