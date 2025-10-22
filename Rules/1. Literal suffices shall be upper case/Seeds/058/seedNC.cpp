// Context: Engine fuel injector timing calculator

#include <iostream>
int main() {
    const float injectorDelay = 0.005f;
    const unsigned rpm = 6000u;
    const long baseTime = 11l;
    std::cout << injectorDelay * rpm + baseTime << std::endl;
    return 0;
}
