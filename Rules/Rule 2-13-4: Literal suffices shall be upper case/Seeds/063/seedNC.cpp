// Context: Autonomous car steering angle compensator

#include <iostream>
#include <cmath>
int main() {
    const float steeringGain = 0.9f;
    const unsigned iterations = 100u;
    const long bias = 3l;
    std::cout << std::cos(steeringGain) * iterations + bias << std::endl;
    return 0;
}
