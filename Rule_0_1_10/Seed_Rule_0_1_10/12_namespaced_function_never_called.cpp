// Seed (Non-compliant): Rule 0-1-10 — namespaced function defined but never called.
#include <iostream>

namespace logx {
    void trace(const char*) { std::cout << "trace\n"; } // defined, never called
}

int main() {
    std::cout << "run\n";
    return 0;
}
