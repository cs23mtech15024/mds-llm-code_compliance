// Seed (Non-compliant): Rule 0-1-10 — function taking references defined but never called.
#include <iostream>

void swap_pair(int& a, int& b) {       // defined, never called
    int t = a; a = b; b = t;
}

int main() {
    int x = 1, y = 2;
    std::cout << x + y << "\n";
    return 0;
}
