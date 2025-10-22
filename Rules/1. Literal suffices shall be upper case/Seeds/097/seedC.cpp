// Context: Aerospace control moment gyroscope tester

#include <iostream>
int main() {
    const float gain = 1.1F;
    const unsigned channels = 8U;
    const long tag = 500L;
    std::cout << gain * channels + tag << '\n';
    return 0;
}
