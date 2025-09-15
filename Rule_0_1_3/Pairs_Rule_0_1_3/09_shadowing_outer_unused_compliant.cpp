// Title: Avoid shadowing or use both variables (Compliant per Rule 0-1-3)
// Seed example: 09_shadowing_hides_use (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int count = 1;
    {
        int inner = 2;
        std::cout << "inner=" << inner << std::endl;
    }
    std::cout << "outer=" << count << std::endl; // use outer
    // Rationale: All variables are referenced; no unused variables remain — compliant.
    return 0;
}