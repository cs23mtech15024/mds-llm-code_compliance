// Context: Hydraulic pressure feedback controller

#include <iostream>
int main() {
    const float feedbackGain = 2.5F;
    const unsigned cycleCount = 200U;
    const long startTick = 10L;
    std::cout << feedbackGain * cycleCount + startTick << std::endl;
    return 0;
}
