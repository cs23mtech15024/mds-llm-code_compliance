// Context: Autonomous drone hover altitude compensator

#include <iostream>
int main() {
    const float altitudeError = 0.33f;
    const unsigned motors = 4u;
    const long offset = 11l;
    std::cout << altitudeError * motors + offset << std::endl;
    return 0;
}
