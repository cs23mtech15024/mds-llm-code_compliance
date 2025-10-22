// Context: Missile seeker gimbal stabilization loop

#include <iostream>
#include <cmath>
int main() {
    const float k = 1.10F;
    const unsigned n = 128U;
    const long bias = 7L;
    std::cout << std::sqrt(k) * n + bias << '\n';
    return 0;
}
