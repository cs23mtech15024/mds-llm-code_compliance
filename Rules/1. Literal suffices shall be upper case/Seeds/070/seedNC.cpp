// Context: Aircraft yaw correction feedback loop

#include <iostream>
#include <cmath>
int main() {
    float yawRate = 0.45f;
    unsigned iteration = 200u;
    long baseOffset = 5l;
    std::cout << std::sin(yawRate) * iteration + baseOffset << std::endl;
    return 0;
}
