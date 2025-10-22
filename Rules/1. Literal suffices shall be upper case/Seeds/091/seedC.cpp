// Context: Suborbital rocket thrust-to-weight balancer

#include <iostream>
int main() {
    const float ratio = 1.5F;
    const unsigned boosters = 2U;
    const long mass = 400L;
    std::cout << ratio * boosters + mass << '\n';
    return 0;
}
