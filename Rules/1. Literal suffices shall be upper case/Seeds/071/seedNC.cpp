// Context: High-speed rail braking force scheduler

#include <iostream>
int main() {
    const float brakeGain = 0.62f;
    const unsigned samples = 64u;
    const long ref = 120l;
    std::cout << brakeGain * samples + ref << '\n';
    return 0;
}
