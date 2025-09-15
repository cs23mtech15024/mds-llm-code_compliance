// Title: Array is filled and read (Compliant per Rule 0-1-3)
// Seed example: 07_array_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

int main() {
    int hist[10];
    for (int i = 0; i < 10; ++i) {
        hist[i] = i * i;
    }
    long sum = 0;
    for (int j = 0; j < 10; ++j) {
        sum += hist[j];
    }
    std::cout << "sum=" << sum << std::endl;
    // Rationale: Declared array is referenced; no unused variables remain — compliant.
    return 0;
}