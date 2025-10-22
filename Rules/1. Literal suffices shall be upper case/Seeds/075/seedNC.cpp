// Context: Autonomous forklift load height governor

#include <iostream>
int main() {
    const float heightGain = 0.8f;
    const unsigned ticks = 40u;
    const long ref = 12l;
    std::cout << heightGain * ticks + ref << '\n';
    return 0;
}
