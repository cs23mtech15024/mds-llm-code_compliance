// Context: Space probe antenna pointing refinement

#include <iostream>
int main() {
    const float refine = 0.005F;
    const unsigned cycles = 500U;
    const long epoch = 2033L;
    std::cout << refine * cycles + epoch << '\n';
    return 0;
}
