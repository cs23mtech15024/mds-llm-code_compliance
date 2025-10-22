// Context: Aircraft flap position scheduler

#include <iostream>
int main() {
    const float flapGain = 9.81f;
    const unsigned delay = 50u;
    const long ref = 2024l;
    const unsigned mask = 0x1234u;
    std::cout << flapGain * delay + ref + mask << std::endl;
    return 0;
}
