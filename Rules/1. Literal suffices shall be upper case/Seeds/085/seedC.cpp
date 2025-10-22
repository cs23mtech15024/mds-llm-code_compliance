// Context: Automotive engine idle speed compensator

#include <iostream>
int main() {
    const float idleGain = 1.3F;
    const unsigned rpm = 900U;
    const long offset = 3L;
    std::cout << idleGain * rpm + offset << '\n';
    return 0;
}
