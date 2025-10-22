// Context: Industrial robotic arm jerk limiter

#include <iostream>
int main() {
    const float jerk = 0.015F;
    const unsigned segment = 6U;
    const long seq = 700L;
    std::cout << jerk * segment + seq << '\n';
    return 0;
}
