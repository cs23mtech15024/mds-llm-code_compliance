// Context: Satellite solar array alignment controller

#include <iostream>
int main() {
    const float alignGain = 1.2f;
    const unsigned ticks = 120u;
    const long missionTime = 2048l;
    std::cout << alignGain * ticks + missionTime << std::endl;
    return 0;
}
