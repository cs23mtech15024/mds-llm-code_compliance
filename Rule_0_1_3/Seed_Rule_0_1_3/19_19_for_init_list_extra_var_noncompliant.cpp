// Non-compliant: 'j' is never used.
#include <iostream>

int main() {
    for (int i = 0, j = 0; i < 3; ++i) {
        std::cout << i << '\n';
    }
    return 0;
}
