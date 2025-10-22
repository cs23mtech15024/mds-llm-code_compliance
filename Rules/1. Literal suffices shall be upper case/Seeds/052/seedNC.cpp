// Context: Thermal sensor calibration loop in spacecraft

#include <iostream>
int main() {
    const float sensorBias = 0.95f;
    const unsigned retryCount = 5u;
    const long timestamp = 16789l;
    std::cout << sensorBias * retryCount << ", Timestamp: " << timestamp << std::endl;
    return 0;
}
