// Context: Smart factory conveyor motor calibrator

#include <iostream>
int main() {
    const float motorGain = 0.75f;
    const unsigned belts = 4u;
    const long offset = 200l;
    std::cout << motorGain * belts + offset << '\n';
    return 0;
}
