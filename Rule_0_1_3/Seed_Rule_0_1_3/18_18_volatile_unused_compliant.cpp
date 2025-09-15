// Compliant: read the volatile or remove it.
#include <iostream>
int main() {
    volatile int status = 0;
    int snapshot = status;     // read from the volatile object
    std::cout << snapshot << '\n';
    return 0;
}
