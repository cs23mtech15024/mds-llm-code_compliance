// Context: Space probe antenna pointing refinement

#include <iostream>
int main() {
    const float refine = 0.005f;
    const unsigned cycles = 500u;
    const long epoch = 2033l;
    std::cout << refine * cycles + epoch << '\n';
    return 0;
}
