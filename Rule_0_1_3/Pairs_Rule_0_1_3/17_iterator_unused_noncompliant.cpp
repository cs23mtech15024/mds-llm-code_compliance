// Title: Iterator declared but never used (Non-compliant per Rule 0-1-3)
// Seed example: 17_iterator_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i);
    std::vector<int>::iterator it = v.begin(); // UNUSED (violates Rule 0-1-3)
    std::cout << "size=" << v.size() << std::endl;
    // Rationale: 'it' is never referenced; unused variable.
    return 0;
}