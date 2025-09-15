// Compliant: remove or use the variable in the try block.
#include <stdexcept>
#include <iostream>

int main() {
    try {
        int attempts = 0;
        ++attempts;
        throw std::runtime_error("x");
    } catch (const std::exception&) {
    }
    return 0;
}
