// Context: Railgun capacitor charge timing circuit

#include <iostream>
int main() {
    const float chargeRate = 0.005f;
    const unsigned capacitorCount = 8u;
    const long baseTime = 50l;
    std::cout << chargeRate * capacitorCount + baseTime << std::endl;
    return 0;
}
