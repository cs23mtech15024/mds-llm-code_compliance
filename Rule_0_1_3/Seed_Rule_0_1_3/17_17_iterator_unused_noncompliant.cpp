// Non-compliant: iterator is declared but never used.
#include <vector>

int main() {
    std::vector<int> v(3, 1);
    std::vector<int>::iterator it = v.begin(); // unused
    return 0;
}
