// Context: Aerospace flight recorder timestamp validator

#include <iostream>
int main() {
    const float rate = 0.05f;
    const unsigned samples = 1024u;
    const long base = 4096l;
    std::cout << rate * samples + base << '\n';
    return 0;
}
