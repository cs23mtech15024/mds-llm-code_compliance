// Non-compliant: variable declared but not referenced; sizeof(type) doesn't use 'n'.
#include <cstddef>

int main() {
    int n; // unused
    std::size_t s = sizeof(int);
    (void)s;
    return 0;
}
