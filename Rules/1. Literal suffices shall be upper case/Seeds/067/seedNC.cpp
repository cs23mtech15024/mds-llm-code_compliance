// Context: Power plant turbine speed synchronizer

#include <iostream>
int main() {
    const float turbineGain = 2.0f;
    const unsigned rpm = 3000u;
    const long adjust = 5l;
    std::cout << turbineGain * rpm + adjust << std::endl;
    return 0;
}
