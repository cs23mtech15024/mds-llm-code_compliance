// Context: Satellite solar array alignment controller

#include <iostream>
int main() {
    const float alignGain = 1.2F;
    const unsigned ticks = 120U;
    const long missionTime = 2048L;
    std::cout << alignGain * ticks + missionTime << std::endl;
    return 0;
}
