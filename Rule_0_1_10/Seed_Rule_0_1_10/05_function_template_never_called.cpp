// Seed (Non-compliant): Rule 0-1-10 — function template defined but never called.
#include <iostream>

template <typename T>
T square(T x) {                        // defined template, never called
    return x * x;
}

int main() {
    std::cout << "ok\n";
    return 0;
}
