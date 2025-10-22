// Context: Robotic arm torque balance calibration

#include <iostream>
int main() {
    const float balance = 2.75f;
    const unsigned joints = 5u;
    const long index = 90l;
    std::cout << balance * joints + index << '\n';
    return 0;
}
