// Context: Nuclear reactor coolant pump ramp controller

#include <iostream>
int main() {
    const float ramp = 0.04f;
    const unsigned stages = 10u;
    const long tag = 3001l;
    std::cout << ramp * stages + tag << '\n';
    return 0;
}
