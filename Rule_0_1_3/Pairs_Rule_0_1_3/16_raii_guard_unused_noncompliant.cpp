// Title: Named RAII guard declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 16_temporary_raii_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

struct Guard {
    Guard()  { std::cout << "acquire\n"; }
    ~Guard() { std::cout << "release\n"; }
};

int main() {
    Guard g; // UNUSED name (violates Rule 0-1-3) — destructor side-effect isn't a "use"
    std::cout << "work\n";
    // Rationale: The named variable 'g' is never referenced despite construction/destruction.
    return 0;
}