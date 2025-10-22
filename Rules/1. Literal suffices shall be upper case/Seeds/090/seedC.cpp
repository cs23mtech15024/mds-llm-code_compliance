// Context: Autonomous ship rudder feedback controller

#include <iostream>
#include <cmath>
int main() {
    float rudderAngle = 0.9F;
    unsigned steps = 400U;
    long offset = 15L;
    std::cout << std::cos(rudderAngle) * steps + offset << '\n';
    return 0;
}
