// Title: Anonymous-namespace function never called (Non-compliant — Rule 0-1-10)
// Seed source: 03_placeholder_never_called.cpp
#include <iostream>

namespace {
    void hidden_checksum() { std::cout << "chk\n"; } // defined, NEVER called
}

int main() {
    std::cout << "start" << std::endl;
    // Rationale: hidden_checksum has internal linkage and is never invoked; non-compliant.
    return 0;
}
