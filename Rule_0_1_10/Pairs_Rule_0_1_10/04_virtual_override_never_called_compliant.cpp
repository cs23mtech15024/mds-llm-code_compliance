// Title: Virtual override is invoked via dynamic dispatch (Compliant — Rule 0-1-10)
// Seed source: 04 (virtual override) — corrected
#include <iostream>

struct Base {
    virtual void tick() { std::cout << "Base::tick\n"; }
};

struct Derived : Base {
    virtual void tick() { std::cout << "Derived::tick\n"; } // now exercised
};

int main() {
    Base* p = new Derived();
    p->tick();   // virtual dispatch calls Derived::tick
    delete p;
    // Rationale: The defined override is invoked; compliant with Rule 0-1-10.
    return 0;
}
