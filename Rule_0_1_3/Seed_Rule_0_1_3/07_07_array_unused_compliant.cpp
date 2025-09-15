// Compliant: use array contents or remove it.
#include <iostream>
int main() {
    int buf[16] = {0};
    buf[0] = 123;
    std::cout << buf[0] << '\n';
    return 0;
}
