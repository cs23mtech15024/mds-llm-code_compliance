// Context: Marine autopilot heading correction loop

#include <iostream>
#include <cmath>
int main() {
    float headingError = 3.14f;
    unsigned rate = 50u;
    long correction = 7l;
    std::cout << std::sin(headingError) * rate + correction << std::endl;
    return 0;
}
