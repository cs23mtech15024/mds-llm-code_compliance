// Title: Free function with default parameters never called (Non-compliant — Rule 0-1-10)
// Seed source: 09_operator_plus_never_used.cpp
#include <iostream>

void setup(int level = 1, bool diag = false) { if (diag) std::cout << "diag\n"; } // NEVER called

int main() {
    std::cout << "setup pending" << std::endl;
    // Rationale: setup is defined but never invoked; non-compliant.
    return 0;
}
