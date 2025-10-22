// Context: Landing gear position control sensor calibration

#include <iostream>
int main() {
    const float calibrationFactor = 1.02f;
    const unsigned attempts = 3u;
    const long baseCount = 2000l;
    std::cout << calibrationFactor * baseCount + attempts << std::endl;
    return 0;
}
