// Context: Chemical process pressure valve regulator

#include <iostream>
int main() {
    const float pressureGain = 2.2F;
    const unsigned valves = 6U;
    const long setpoint = 10L;
    std::cout << pressureGain * valves + setpoint << '\n';
    return 0;
}
