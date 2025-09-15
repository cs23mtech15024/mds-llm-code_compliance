// Seed (Non-compliant): Rule 0-1-10 — static member function defined but never called.
#include <iostream>

struct Util {
    static void ping() { std::cout << "ping\n"; } // defined, never called
};

int main() {
    std::cout << "ok\n";
    return 0;
}
