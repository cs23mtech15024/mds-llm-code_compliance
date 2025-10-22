// Context: Nuclear reactor coolant flow rate monitor

#include <iostream>
int main() {
    const float flowRate = 5.5f;
    const unsigned cycleTime = 60u;
    const long alertCode = 77l;
    std::cout << flowRate * cycleTime + alertCode << std::endl;
    return 0;
}
