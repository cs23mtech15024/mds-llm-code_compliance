// Title: extern "C" function is called (Compliant — Rule 0-1-10)
// Seed source: 18 (extern "C") — corrected
#include <iostream>

extern "C" void c_port() { std::cout << "c-port\n"; }

int main() {
    c_port(); // actual call
    std::cout << "host" << std::endl;
    // Rationale: c_port is defined and invoked; compliant.
    return 0;
}
