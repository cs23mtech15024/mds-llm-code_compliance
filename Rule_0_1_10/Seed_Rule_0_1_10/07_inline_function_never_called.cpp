// Seed (Non-compliant): Rule 0-1-10 — inline function defined but never called.
#include <iostream>

inline int triple(int v) {             // defined inline, never called
    return v * 3;
}

int main() {
    std::cout << "run\n";
    return 0;
}
