// Seed (Non-compliant): Rule 0-1-10 — function defined for pointer target but never called.
#include <iostream>

int compute(int x) { return x + 1; }   // defined, never called

int main() {
    std::cout << "start\n";
    return 0;
}
