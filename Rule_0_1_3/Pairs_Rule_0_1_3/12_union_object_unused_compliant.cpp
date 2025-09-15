// Title: Union variable is written and read (Compliant per Rule 0-1-3)
// Seed example: 12_union_var_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

union U {
    int i;
    float f;
};

int main() {
    U u;
    u.i = 77;              // write
    std::cout << u.i << std::endl; // read
    // Rationale: Union variable is referenced; no unused variables — compliant.
    return 0;
}