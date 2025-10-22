// Context: Wind turbine blade pitch regulator

#include <iostream>
int main() {
    const float pitchRate = 0.6f;
    const unsigned blades = 3u;
    const long controllerID = 900l;
    std::cout << pitchRate * blades + controllerID << std::endl;
    return 0;
}
