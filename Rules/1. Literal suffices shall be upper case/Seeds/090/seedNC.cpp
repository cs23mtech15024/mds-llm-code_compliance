// Context: Autonomous ship rudder feedback controller

#include <iostream>
#include <cmath>
int main() {
    float rudderAngle = 0.9f;
    unsigned steps = 400u;
    long offset = 15l;
    std::cout << std::cos(rudderAngle) * steps + offset << '\n';
    return 0;
}
