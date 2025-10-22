// Context: Power plant turbine speed synchronizer

#include <iostream>
int main() {
    const float turbineGain = 2.0F;
    const unsigned rpm = 3000U;
    const long adjust = 5L;
    std::cout << turbineGain * rpm + adjust << std::endl;
    return 0;
}
