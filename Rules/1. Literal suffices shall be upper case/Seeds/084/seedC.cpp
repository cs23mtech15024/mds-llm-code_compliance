// Context: Weather radar pulse modulation control

#include <iostream>
int main() {
    const float pulseWidth = 0.08F;
    const unsigned sweeps = 64U;
    const long mode = 12L;
    std::cout << pulseWidth * sweeps + mode << '\n';
    return 0;
}
