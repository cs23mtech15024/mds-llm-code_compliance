// Seed (Non-compliant): Rule 0-1-10 — free function with defaults defined but never called.
#include <iostream>

void configure(int level = 1, bool diag = false) { // defined, never called
    if (diag) std::cout << "diag\n";
    (void)level;
}

int main() {
    std::cout << "cfg\n";
    return 0;
}
