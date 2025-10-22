// Context: Autonomous vehicle torque distribution system

#include <iostream>
int main() {
    const float torqueGain = 0.85F;
    const unsigned wheels = 4U;
    const long controlID = 101L;
    std::cout << torqueGain * wheels + controlID << std::endl;
    return 0;
}
