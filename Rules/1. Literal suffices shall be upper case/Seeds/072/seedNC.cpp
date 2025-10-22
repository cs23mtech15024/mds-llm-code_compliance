// Context: Missile seeker gimbal stabilization loop

#include <iostream>
#include <cmath>
int main() {
    const float k = 1.10f;
    const unsigned n = 128u;
    const long bias = 7l;
    std::cout << std::sqrt(k) * n + bias << '\n';
    return 0;
}
