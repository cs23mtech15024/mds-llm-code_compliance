// Title: Every overload is exercised at least once (Compliant — Rule 0-1-10)
// Seed source: 08 (overloads) — corrected
#include <iostream>

void write(int)         { std::cout << "int\n"; }
void write(const char*) { std::cout << "cstr\n"; }
void write(double)      { std::cout << "double\n"; }

int main() {
    write(5);
    write("x");
    write(3.14); // exercise double overload
    // Rationale: All defined overloads are called; compliant.
    return 0;
}
