// Context: Chemical process pressure valve regulator

#include <iostream>
int main() {
    const float pressureGain = 2.2f;
    const unsigned valves = 6u;
    const long setpoint = 10l;
    std::cout << pressureGain * valves + setpoint << '\n';
    return 0;
}
