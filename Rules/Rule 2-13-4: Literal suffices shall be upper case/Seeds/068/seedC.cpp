// Context: Railgun capacitor charge timing circuit

#include <iostream>
int main() {
    const float chargeRate = 0.005F;
    const unsigned capacitorCount = 8U;
    const long baseTime = 50L;
    std::cout << chargeRate * capacitorCount + baseTime << std::endl;
    return 0;
}
