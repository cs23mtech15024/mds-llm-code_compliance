// Context: Railway track temperature monitoring sensor

#include <iostream>
int main() {
    const float tempGain = 0.45F;
    const unsigned checkCount = 25U;
    const long refTemp = 273L;
    std::cout << tempGain * checkCount + refTemp << std::endl;
    return 0;
}
