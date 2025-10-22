// Context: Power grid transformer current limiter

#include <iostream>
int main() {
    const float currentGain = 0.65F;
    const unsigned phases = 3U;
    const long trip = 102L;
    std::cout << currentGain * phases + trip << '\n';
    return 0;
}
