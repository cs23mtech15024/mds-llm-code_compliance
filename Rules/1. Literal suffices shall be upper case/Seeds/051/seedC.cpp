// Context: UAV altitude hold control module

#include <iostream>
int main() {
    const float altitudeGain = 1.25F;
    const unsigned updateRate = 400U;
    const long reference = 1024L;
    std::cout << "Altitude gain: " << altitudeGain << ", Rate: " << updateRate << ", Ref: " << reference << std::endl;
    return 0;
}
