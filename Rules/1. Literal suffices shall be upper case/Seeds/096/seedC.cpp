// Context: Flight simulator turbulence feedback module

#include <iostream>
#include <cmath>
int main() {
    const float feedback = 0.08F;
    const unsigned loops = 80U;
    const long ref = 23L;
    std::cout << std::sin(feedback) * loops + ref << '\n';
    return 0;
}
