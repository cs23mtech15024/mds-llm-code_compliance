// Context: Weather radar pulse modulation control

#include <iostream>
int main() {
    const float pulseWidth = 0.08f;
    const unsigned sweeps = 64u;
    const long mode = 12l;
    std::cout << pulseWidth * sweeps + mode << '\n';
    return 0;
}
