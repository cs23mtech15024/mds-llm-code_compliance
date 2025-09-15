// Title: RAII guard is referenced or made unnamed (Compliant per Rule 0-1-3)
// Seed example: 16_temporary_raii_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

struct Guard {
    Guard()  { std::cout << "acquire\n"; }
    ~Guard() { std::cout << "release\n"; }
    void ping() const { std::cout << "ping\n"; }
};

int main() {
    Guard g;    // keep named
    g.ping();   // USE the guard object explicitly
    std::cout << "work\n";
    // Rationale: The guard object is referenced; no unused variables remain — compliant.
    return 0;
}