// Compliant: avoid shadowing or use the outer variable.
#include <iostream>

int main() {
    int value = 10; 
    {
        int inner = 20;
        std::cout << inner << '\n';
    }
    std::cout << value << '\n';
    return 0;
}
