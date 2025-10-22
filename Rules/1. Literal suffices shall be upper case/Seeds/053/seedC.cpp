// Context: Flight control roll angle estimator

#include <iostream>
#include <cmath>
int main() {
    float rollRate = 0.75F;
    unsigned iterations = 300U;
    long offset = 12L;
    std::cout << "Roll angle: " << std::sin(rollRate) * iterations + offset << std::endl;
    return 0;
}
