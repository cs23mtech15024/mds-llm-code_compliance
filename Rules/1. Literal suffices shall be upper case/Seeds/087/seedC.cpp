// Context: Railway automatic signal delay synchronizer

#include <iostream>
int main() {
    const float delayFactor = 0.2F;
    const unsigned signals = 30U;
    const long ref = 200L;
    std::cout << delayFactor * signals + ref << '\n';
    return 0;
}
