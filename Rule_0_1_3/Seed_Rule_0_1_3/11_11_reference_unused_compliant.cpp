// Compliant: use the reference or avoid creating it.
#include <iostream>
int main() {
    int x = 5;
    int& ref = x;
    ref += 1;
    std::cout << x << '\n';
    return 0;
}
