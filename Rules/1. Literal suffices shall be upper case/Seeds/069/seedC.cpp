// Context: Mars rover wheel torque regulator

#include <iostream>
int main() {
    const float torqueBias = 1.15F;
    const unsigned steps = 150U;
    const long baseTorque = 60L;
    std::cout << torqueBias * steps + baseTorque << std::endl;
    return 0;
}
