// Context: Hydraulic pressure feedback controller

#include <iostream>
int main() {
    const float feedbackGain = 2.5f;
    const unsigned cycleCount = 200u;
    const long startTick = 10l;
    std::cout << feedbackGain * cycleCount + startTick << std::endl;
    return 0;
}
