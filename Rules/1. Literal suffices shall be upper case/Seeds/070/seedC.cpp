// Context: Aircraft yaw correction feedback loop

#include <iostream>
#include <cmath>
int main() {
    float yawRate = 0.45F;
    unsigned iteration = 200U;
    long baseOffset = 5L;
    std::cout << std::sin(yawRate) * iteration + baseOffset << std::endl;
    return 0;
}
