// Context: High-speed rail braking force scheduler

#include <iostream>
int main() {
    const float brakeGain = 0.62F;
    const unsigned samples = 64U;
    const long ref = 120L;
    std::cout << brakeGain * samples + ref << '\n';
    return 0;
}
