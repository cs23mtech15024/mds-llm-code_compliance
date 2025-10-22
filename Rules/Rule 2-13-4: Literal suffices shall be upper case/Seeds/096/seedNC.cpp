// Context: Flight simulator turbulence feedback module

#include <iostream>
#include <cmath>
int main() {
    const float feedback = 0.08f;
    const unsigned loops = 80u;
    const long ref = 23l;
    std::cout << std::sin(feedback) * loops + ref << '\n';
    return 0;
}
