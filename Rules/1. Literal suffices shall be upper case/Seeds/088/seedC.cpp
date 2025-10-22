// Context: Fusion reactor plasma temperature balancer

#include <iostream>
int main() {
    const float tempFactor = 3.9F;
    const unsigned coils = 12U;
    const long cycle = 300L;
    std::cout << tempFactor * coils + cycle << '\n';
    return 0;
}
