// Context: Engine fuel injector timing calculator

#include <iostream>
int main() {
    const float injectorDelay = 0.005F;
    const unsigned rpm = 6000U;
    const long baseTime = 11L;
    std::cout << injectorDelay * rpm + baseTime << std::endl;
    return 0;
}
