// Title: Pointer variable is dereferenced/read (Compliant per Rule 0-1-3)
// Seed example: 06_pointer_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int value = 99;
    int* ptr = &value;
    std::cout << "value=" << *ptr << std::endl; // USE pointer
    // Rationale: All declared variables are used; compliant with Rule 0-1-3.
    return 0;
}