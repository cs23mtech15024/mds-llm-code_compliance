// Title: extern "C" function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 09_placeholder_never_called.cpp
#include <iostream>

extern "C" void c_port() { std::cout << "c-port\n"; } // defined, NEVER called

int main() {
    std::cout << "host" << std::endl;
    // Rationale: c_port is not invoked; non-compliant.
    return 0;
}
