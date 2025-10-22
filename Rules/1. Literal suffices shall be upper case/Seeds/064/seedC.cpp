// Context: Submarine ballast control depth stabilizer

#include <iostream>
int main() {
    const float depthFactor = 1.5F;
    const unsigned valveDelay = 20U;
    const long refDepth = 400L;
    std::cout << depthFactor * valveDelay + refDepth << std::endl;
    return 0;
}
