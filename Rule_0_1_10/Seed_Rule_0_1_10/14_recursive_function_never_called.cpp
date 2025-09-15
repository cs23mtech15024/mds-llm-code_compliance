// Seed (Non-compliant): Rule 0-1-10 — recursive function defined but never called.
#include <iostream>

int fact(int n) {                       // defined, never called
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int main() {
    std::cout << "ok\n";
    return 0;
}
