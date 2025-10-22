// Context: Railway track temperature monitoring sensor

#include <iostream>
int main() {
    const float tempGain = 0.45f;
    const unsigned checkCount = 25u;
    const long refTemp = 273l;
    std::cout << tempGain * checkCount + refTemp << std::endl;
    return 0;
}
