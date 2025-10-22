// Context: Power grid transformer current limiter

#include <iostream>
int main() {
    const float currentGain = 0.65f;
    const unsigned phases = 3u;
    const long trip = 102l;
    std::cout << currentGain * phases + trip << '\n';
    return 0;
}
