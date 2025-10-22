// Context: Aerospace flight recorder timestamp validator

#include <iostream>
int main() {
    const float rate = 0.05F;
    const unsigned samples = 1024U;
    const long base = 4096L;
    std::cout << rate * samples + base << '\n';
    return 0;
}
