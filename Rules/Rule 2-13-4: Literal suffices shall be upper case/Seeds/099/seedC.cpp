// Context: Smart factory conveyor motor calibrator

#include <iostream>
int main() {
    const float motorGain = 0.75F;
    const unsigned belts = 4U;
    const long offset = 200L;
    std::cout << motorGain * belts + offset << '\n';
    return 0;
}
