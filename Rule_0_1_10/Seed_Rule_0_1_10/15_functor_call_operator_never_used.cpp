// Seed (Non-compliant): Rule 0-1-10 — functor's operator() defined but never called.
#include <iostream>

struct Adder {
    int operator()(int a, int b) const { return a + b; } // defined, never called
};

int main() {
    Adder add;
    (void)add; // object created but not invoked
    std::cout << "ready\n";
    return 0;
}
