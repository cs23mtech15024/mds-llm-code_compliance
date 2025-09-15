// Compliant: remove or use the block-scoped variable.
#include <iostream>

int main() {
    int code = 1;
    switch (code) {
        case 1: {
            int temp = 7;
            std::cout << "one " << temp << '\n';
            break;
        }
        default:
            break;
    }
    return 0;
}
