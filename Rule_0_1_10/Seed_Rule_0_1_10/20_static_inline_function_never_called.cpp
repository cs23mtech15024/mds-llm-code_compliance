// Seed (Non-compliant): Rule 0-1-10 — static inline function defined but never called.
#include <iostream>

static inline void banner(const char* s) { std::cout << s << "\n"; } // never called

int main() {
    std::cout << "end\n";
    return 0;
}
