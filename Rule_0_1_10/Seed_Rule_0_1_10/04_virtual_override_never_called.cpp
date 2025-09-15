// Seed (Non-compliant): Rule 0-1-10 — virtual override defined but never invoked.
#include <iostream>

struct Base {
    virtual void tick() { std::cout << "Base\n"; }
};

struct Derived : Base {
    virtual void tick() { std::cout << "Derived\n"; } // defined override, never called
};

int main() {
    Base b;
    b.tick();
    return 0;
}
