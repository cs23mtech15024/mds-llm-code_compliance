// Context: Autonomous drone battery discharge monitor

#include <iostream>
int main() {
    const float discharge = 4.7f;
    const unsigned cells = 6u;
    const long logID = 41l;
    std::cout << discharge * cells + logID << '\n';
    return 0;
}
