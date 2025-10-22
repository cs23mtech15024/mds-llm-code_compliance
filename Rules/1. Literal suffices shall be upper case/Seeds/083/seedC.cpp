// Context: Robotic arm torque balance calibration

#include <iostream>
int main() {
    const float balance = 2.75F;
    const unsigned joints = 5U;
    const long index = 90L;
    std::cout << balance * joints + index << '\n';
    return 0;
}
