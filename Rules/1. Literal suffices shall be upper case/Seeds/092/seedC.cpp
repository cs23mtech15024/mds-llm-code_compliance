// Context: Drone propeller synchronization circuit

#include <iostream>
int main() {
    const float sync = 0.015F;
    const unsigned props = 4U;
    const long delay = 33L;
    std::cout << sync * props + delay << '\n';
    return 0;
}
