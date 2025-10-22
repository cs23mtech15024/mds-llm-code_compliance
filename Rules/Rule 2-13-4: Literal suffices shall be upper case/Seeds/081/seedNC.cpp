// Context: Space telescope mirror alignment algorithm

#include <iostream>
int main() {
    const float alignRate = 0.003f;
    const unsigned actuators = 18u;
    const long session = 250l;
    std::cout << alignRate * actuators + session << '\n';
    return 0;
}
