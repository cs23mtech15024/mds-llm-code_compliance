// Title: Union variable declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 12_union_var_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

union U {
    int i;
    float f;
};

int main() {
    U u; // UNUSED (violates Rule 0-1-3)
    std::cout << "ok" << std::endl;
    // Rationale: 'u' is never read/written; unused variable.
    return 0;
}