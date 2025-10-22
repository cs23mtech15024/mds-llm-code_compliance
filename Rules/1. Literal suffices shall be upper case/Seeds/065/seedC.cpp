// Context: Wind turbine blade pitch regulator

#include <iostream>
int main() {
    const float pitchRate = 0.6F;
    const unsigned blades = 3U;
    const long controllerID = 900L;
    std::cout << pitchRate * blades + controllerID << std::endl;
    return 0;
}
