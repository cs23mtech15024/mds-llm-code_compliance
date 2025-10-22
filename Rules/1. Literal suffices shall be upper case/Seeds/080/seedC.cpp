// Context: Precision CNC spindle thermal drift corrector

#include <iostream>
int main() {
    const float drift = 0.002F;
    const unsigned passes = 120U;
    const long base = 450L;
    std::cout << drift * passes + base << '\n';
    return 0;
}
