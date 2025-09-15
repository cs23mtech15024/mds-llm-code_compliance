// Title: Friend function defined but never used (Non-compliant — Rule 0-1-10)
// Seed source: 05_placeholder_never_called.cpp
#include <iostream>

class Box {
    int v;
public:
    Box(int w): v(w) {}
    friend int surface(const Box& b) { return b.v * 6; } // defined, NEVER called
};

int main() {
    Box b(3);
    std::cout << "box" << std::endl;
    // Rationale: 'surface' is defined but never invoked; non-compliant.
    return 0;
}
