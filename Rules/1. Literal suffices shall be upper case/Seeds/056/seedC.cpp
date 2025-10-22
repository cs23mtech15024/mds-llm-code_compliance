// Context: Nuclear reactor coolant flow rate monitor

#include <iostream>
int main() {
    const float flowRate = 5.5F;
    const unsigned cycleTime = 60U;
    const long alertCode = 77L;
    std::cout << flowRate * cycleTime + alertCode << std::endl;
    return 0;
}
