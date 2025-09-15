// Title: Free function with defaults is called (Compliant — Rule 0-1-10)
// Seed source: 17 (defaults) — corrected
#include <iostream>

void setup(int level = 1, bool diag = false) { if (diag) std::cout << "diag\n"; }

int main() {
    setup();           // exercise defaults
    setup(2, true);    // exercise explicit args
    // Rationale: Defined function is invoked at least once; compliant.
    return 0;
}
