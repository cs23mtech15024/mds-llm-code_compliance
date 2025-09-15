// Compliant: remove or use the pointer properly.
#include <iostream>
int main() {
    int x = 42;
    int* p = &x;
    std::cout << *p << '\n';
    return 0;
}
