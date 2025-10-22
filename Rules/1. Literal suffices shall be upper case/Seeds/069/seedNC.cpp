// Context: Mars rover wheel torque regulator

#include <iostream>
int main() {
    const float torqueBias = 1.15f;
    const unsigned steps = 150u;
    const long baseTorque = 60l;
    std::cout << torqueBias * steps + baseTorque << std::endl;
    return 0;
}
