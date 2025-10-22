// Context: Fusion reactor plasma temperature balancer

#include <iostream>
int main() {
    const float tempFactor = 3.9f;
    const unsigned coils = 12u;
    const long cycle = 300l;
    std::cout << tempFactor * coils + cycle << '\n';
    return 0;
}
