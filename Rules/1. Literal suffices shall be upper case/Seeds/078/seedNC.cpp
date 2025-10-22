// Context: Industrial robotic arm jerk limiter

#include <iostream>
int main() {
    const float jerk = 0.015f;
    const unsigned segment = 6u;
    const long seq = 700l;
    std::cout << jerk * segment + seq << '\n';
    return 0;
}
