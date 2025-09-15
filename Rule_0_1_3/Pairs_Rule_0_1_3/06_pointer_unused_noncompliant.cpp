// Title: Pointer variable declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 06_pointer_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int value = 99;
    int* ptr = &value; // UNUSED (violates Rule 0-1-3)
    std::cout << "ready" << std::endl;
    // Rationale: 'ptr' is never dereferenced/read; unused variable violates Rule 0-1-3.
    return 0;
}