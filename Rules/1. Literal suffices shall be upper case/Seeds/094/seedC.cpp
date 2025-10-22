// Context: Spacecraft attitude gyro correction

#include <iostream>
int main() {
    const float gyroBias = 0.003F;
    const unsigned axes = 3U;
    const long time = 44L;
    std::cout << gyroBias * axes + time << '\n';
    return 0;
}
