// Compliant: ensure the variable is used regardless of NDEBUG.
#include <cassert>
#include <iostream>

int compute() { return 42; }

int main() {
#ifndef NDEBUG
    int result = compute();
    assert(result == 42);
    std::cout << result << '\n';
#else
    // Release: call without introducing an unused variable
    std::cout << compute() << '\n';
#endif
    return 0;
}
