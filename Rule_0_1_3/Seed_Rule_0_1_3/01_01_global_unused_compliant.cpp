// Compliant: removed unused global or actually use it.
#include <cstdint>
#include <iostream>

int g_counter = 0;

int main() {
    // Use the variable meaningfully
    g_counter += 1;
    std::cout << g_counter << '\n';
    return 0;
}
