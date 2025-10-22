// Context: Marine autopilot cross-track error limiter

#include <iostream>
int main() {
    const float cte = 1.75F;
    const unsigned window = 16U;
    const long base = 5L;
    std::cout << cte * window + base << '\n';
    return 0;
}
