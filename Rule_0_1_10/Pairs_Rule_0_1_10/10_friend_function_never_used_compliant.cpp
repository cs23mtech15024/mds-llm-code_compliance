// Title: Friend function is called (Compliant — Rule 0-1-10)
// Seed source: 10 (friend) — corrected
#include <iostream>

class Box {
    int v;
public:
    Box(int w): v(w) {}
    friend int surface(const Box& b) { return b.v * 6; }
};

int main() {
    Box b(3);
    std::cout << surface(b) << std::endl; // actual call
    // Rationale: Friend function is defined and invoked; compliant.
    return 0;
}
