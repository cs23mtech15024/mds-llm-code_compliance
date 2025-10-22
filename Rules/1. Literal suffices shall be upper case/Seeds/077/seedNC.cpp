// Context: Medical ventilator tidal volume compensator

#include <iostream>
int main() {
    const float volGain = 0.12f;
    const unsigned breaths = 20u;
    const long tag = 88l;
    std::cout << volGain * breaths + tag << '\n';
    return 0;
}
