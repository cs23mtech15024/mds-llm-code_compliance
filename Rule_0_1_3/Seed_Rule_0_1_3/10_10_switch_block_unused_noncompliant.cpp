// Non-compliant: declared variable in case block is unused.
#include <iostream>

int main() {
    int code = 1;
    switch (code) {
        case 1: {
            int temp; // unused
            std::cout << "one\n";
            break;
        }
        default:
            break;
    }
    return 0;
}
