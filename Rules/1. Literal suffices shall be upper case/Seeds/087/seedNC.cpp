// Context: Railway automatic signal delay synchronizer

#include <iostream>
int main() {
    const float delayFactor = 0.2f;
    const unsigned signals = 30u;
    const long ref = 200l;
    std::cout << delayFactor * signals + ref << '\n';
    return 0;
}
