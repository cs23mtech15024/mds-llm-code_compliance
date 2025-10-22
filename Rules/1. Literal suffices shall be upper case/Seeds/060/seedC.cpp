// Context: Aircraft flap position scheduler

#include <iostream>
int main() {
    const float flapGain = 9.81F;
    const unsigned delay = 50U;
    const long ref = 2024L;
    const unsigned mask = 0X1234U;
    std::cout << flapGain * delay + ref + mask << std::endl;
    return 0;
}
