// Context: Autonomous drone battery discharge monitor

#include <iostream>
int main() {
    const float discharge = 4.7F;
    const unsigned cells = 6U;
    const long logID = 41L;
    std::cout << discharge * cells + logID << '\n';
    return 0;
}
