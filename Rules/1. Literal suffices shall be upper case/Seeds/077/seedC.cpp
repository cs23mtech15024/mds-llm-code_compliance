// Context: Medical ventilator tidal volume compensator

#include <iostream>
int main() {
    const float volGain = 0.12F;
    const unsigned breaths = 20U;
    const long tag = 88L;
    std::cout << volGain * breaths + tag << '\n';
    return 0;
}
