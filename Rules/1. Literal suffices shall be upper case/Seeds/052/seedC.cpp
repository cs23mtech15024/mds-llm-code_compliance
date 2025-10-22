// Context: Thermal sensor calibration loop in spacecraft

#include <iostream>
int main() {
    const float sensorBias = 0.95F;
    const unsigned retryCount = 5U;
    const long timestamp = 16789L;
    std::cout << sensorBias * retryCount << ", Timestamp: " << timestamp << std::endl;
    return 0;
}
