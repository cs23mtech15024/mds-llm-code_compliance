// Context: Space telescope mirror alignment algorithm

#include <iostream>
int main() {
    const float alignRate = 0.003F;
    const unsigned actuators = 18U;
    const long session = 250L;
    std::cout << alignRate * actuators + session << '\n';
    return 0;
}
