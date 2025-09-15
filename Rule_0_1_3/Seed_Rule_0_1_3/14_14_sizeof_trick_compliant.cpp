// Compliant: if sizeof is needed for the variable, reference the variable itself.
#include <cstddef>
#include <iostream>

int main() {
    int n = 0;
    std::size_t s = sizeof n; // uses 'n' (unevaluated, but a reference)
    std::cout << s << '\n';
    return 0;
}
