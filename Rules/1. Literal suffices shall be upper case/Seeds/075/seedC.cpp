// Context: Autonomous forklift load height governor

#include <iostream>
int main() {
    const float heightGain = 0.8F;
    const unsigned ticks = 40U;
    const long ref = 12L;
    std::cout << heightGain * ticks + ref << '\n';
    return 0;
}
