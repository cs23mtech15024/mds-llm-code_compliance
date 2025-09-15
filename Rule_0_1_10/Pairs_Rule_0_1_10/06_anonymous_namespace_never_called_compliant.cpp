// Title: Anonymous-namespace function is called (Compliant — Rule 0-1-10)
// Seed source: 06 (anonymous namespace) — corrected
#include <iostream>

namespace {
    void hidden_checksum() { std::cout << "chk\n"; }
}

int main() {
    hidden_checksum(); // actual call
    std::cout << "start" << std::endl;
    // Rationale: hidden_checksum is defined and invoked; compliant.
    return 0;
}
