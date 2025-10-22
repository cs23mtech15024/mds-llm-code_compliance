// Context: Nuclear reactor coolant pump ramp controller

#include <iostream>
int main() {
    const float ramp = 0.04F;
    const unsigned stages = 10U;
    const long tag = 3001L;
    std::cout << ramp * stages + tag << '\n';
    return 0;
}
