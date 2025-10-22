// Context: Spacecraft attitude gyro correction

#include <iostream>
int main() {
    const float gyroBias = 0.003f;
    const unsigned axes = 3u;
    const long time = 44l;
    std::cout << gyroBias * axes + time << '\n';
    return 0;
}
