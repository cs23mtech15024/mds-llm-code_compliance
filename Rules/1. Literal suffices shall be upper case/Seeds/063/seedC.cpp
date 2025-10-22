// Context: Autonomous car steering angle compensator

#include <iostream>
#include <cmath>
int main() {
    const float steeringGain = 0.9F;
    const unsigned iterations = 100U;
    const long bias = 3L;
    std::cout << std::cos(steeringGain) * iterations + bias << std::endl;
    return 0;
}
