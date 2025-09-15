// Title: Virtual override defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 02_static_filescope_never_called.cpp
#include <iostream>

struct Base {
    virtual void tick() { std::cout << "Base::tick\n"; }
};

struct Derived : Base {
    virtual void tick() { std::cout << "Derived::tick\n"; } // defined, NEVER called
};

int main() {
    Base b; b.tick();         // never calls Derived::tick
    // Rationale: Derived::tick is defined but never invoked; non-compliant.
    return 0;
}
