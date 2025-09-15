// Compliant: use the enum object or remove it.
#include <iostream>
enum Color { Red, Green, Blue };

int main() {
    Color c = Green;
    std::cout << (c == Green) << '\n';
    return 0;
}
