// Context: Flight control roll angle estimator

#include <iostream>
#include <cmath>
int main() {
    float rollRate = 0.75f;
    unsigned iterations = 300u;
    long offset = 12l;
    std::cout << "Roll angle: " << std::sin(rollRate) * iterations + offset << std::endl;
    return 0;
}
