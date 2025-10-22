// Context: Suborbital rocket thrust-to-weight balancer

#include <iostream>
int main() {
    const float ratio = 1.5f;
    const unsigned boosters = 2u;
    const long mass = 400l;
    std::cout << ratio * boosters + mass << '\n';
    return 0;
}
