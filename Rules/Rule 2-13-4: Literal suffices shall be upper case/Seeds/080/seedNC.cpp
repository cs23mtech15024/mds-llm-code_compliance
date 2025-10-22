// Context: Precision CNC spindle thermal drift corrector

#include <iostream>
int main() {
    const float drift = 0.002f;
    const unsigned passes = 120u;
    const long base = 450l;
    std::cout << drift * passes + base << '\n';
    return 0;
}
