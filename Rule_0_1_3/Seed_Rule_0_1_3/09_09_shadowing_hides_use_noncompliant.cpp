// Non-compliant: outer variable never used because of shadowing.
#include <iostream>

int main() {
    int value = 10; // outer 'value' unused
    {
        int value = 20; // shadows outer
        std::cout << value << '\n';
    }
    return 0;
}
