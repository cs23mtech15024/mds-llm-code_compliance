// Title: Iterator is used in traversal (Compliant per Rule 0-1-3)
// Seed example: 17_iterator_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Rationale: All declared variables (including iterators) are referenced; compliant.
    return 0;
}