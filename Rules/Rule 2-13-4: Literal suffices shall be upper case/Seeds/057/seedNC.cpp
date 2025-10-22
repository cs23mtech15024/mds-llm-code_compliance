// Context: Autonomous vehicle torque distribution system

#include <iostream>
int main() {
    const float torqueGain = 0.85f;
    const unsigned wheels = 4u;
    const long controlID = 101l;
    std::cout << torqueGain * wheels + controlID << std::endl;
    return 0;
}
