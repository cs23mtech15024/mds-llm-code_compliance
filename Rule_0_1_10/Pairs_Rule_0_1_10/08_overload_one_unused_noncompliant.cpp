// Title: Overload set has unused overload (Non-compliant — Rule 0-1-10)
// Seed source: 04_virtual_override_never_called.cpp
#include <iostream>

void write(int)        { std::cout << "int\n"; }
void write(const char*){ std::cout << "cstr\n"; }
void write(double)     { std::cout << "double\n"; } // defined, NEVER called

int main() {
    write(5);
    write("x");
    // Rationale: write(double) is defined but never invoked; non-compliant.
    return 0;
}
