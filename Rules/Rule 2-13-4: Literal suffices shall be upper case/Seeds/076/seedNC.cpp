// Context: Marine autopilot cross-track error limiter

#include <iostream>
int main() {
    const float cte = 1.75f;
    const unsigned window = 16u;
    const long base = 5l;
    std::cout << cte * window + base << '\n';
    return 0;
}
