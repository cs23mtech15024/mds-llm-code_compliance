// Context: Autonomous drone hover altitude compensator

#include <iostream>
int main() {
    const float altitudeError = 0.33F;
    const unsigned motors = 4U;
    const long offset = 11L;
    std::cout << altitudeError * motors + offset << std::endl;
    return 0;
}
