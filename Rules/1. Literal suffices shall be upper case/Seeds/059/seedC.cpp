// Context: Marine autopilot heading correction loop

#include <iostream>
#include <cmath>
int main() {
    float headingError = 3.14F;
    unsigned rate = 50U;
    long correction = 7L;
    std::cout << std::sin(headingError) * rate + correction << std::endl;
    return 0;
}
