// Non-compliant: variable declared in try block and never used.
#include <stdexcept>

int main() {
    try {
        int attempts = 0; // unused
        throw std::runtime_error("x");
    } catch (const std::exception&) {
    }
    return 0;
}
