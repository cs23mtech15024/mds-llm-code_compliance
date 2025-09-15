// Compliant: use the iterator or avoid declaring it.
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v(3, 1);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << '\n';
    }
    return 0;
}
