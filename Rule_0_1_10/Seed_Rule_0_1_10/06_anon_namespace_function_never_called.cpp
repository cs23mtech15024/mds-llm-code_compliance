// Seed (Non-compliant): Rule 0-1-10 — function in anonymous namespace never called.
#include <iostream>

namespace {
    void hidden() {                    // defined, never called
        std::cout << "hidden\n";
    }
}

int main() {
    std::cout << "work\n";
    return 0;
}
