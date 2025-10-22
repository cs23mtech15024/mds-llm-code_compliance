// Context: Drone propeller synchronization circuit

#include <iostream>
int main() {
    const float sync = 0.015f;
    const unsigned props = 4u;
    const long delay = 33l;
    std::cout << sync * props + delay << '\n';
    return 0;
}
