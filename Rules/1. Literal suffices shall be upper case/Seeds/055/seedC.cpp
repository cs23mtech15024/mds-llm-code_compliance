// Context: Landing gear position control sensor calibration

#include <iostream>
int main() {
    const float calibrationFactor = 1.02F;
    const unsigned attempts = 3U;
    const long baseCount = 2000L;
    std::cout << calibrationFactor * baseCount + attempts << std::endl;
    return 0;
}
