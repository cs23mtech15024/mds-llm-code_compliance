// Context: Submarine ballast control depth stabilizer

#include <iostream>
int main() {
    const float depthFactor = 1.5f;
    const unsigned valveDelay = 20u;
    const long refDepth = 400l;
    std::cout << depthFactor * valveDelay + refDepth << std::endl;
    return 0;
}
