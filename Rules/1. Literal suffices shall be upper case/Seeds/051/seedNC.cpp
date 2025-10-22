// Context: UAV altitude hold control module

#include <iostream>
int main() {
    const float altitudeGain = 1.25f;
    const unsigned updateRate = 400u;
    const long reference = 1024l;
    std::cout << "Altitude gain: " << altitudeGain << ", Rate: " << updateRate << ", Ref: " << reference << std::endl;
    return 0;
}
