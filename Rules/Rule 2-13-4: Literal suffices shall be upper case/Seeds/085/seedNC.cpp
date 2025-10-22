// Context: Automotive engine idle speed compensator

#include <iostream>
int main() {
    const float idleGain = 1.3f;
    const unsigned rpm = 900u;
    const long offset = 3l;
    std::cout << idleGain * rpm + offset << '\n';
    return 0;
}
