// Context: Aerospace control moment gyroscope tester

#include <iostream>
int main() {
    const float gain = 1.1f;
    const unsigned channels = 8u;
    const long tag = 500l;
    std::cout << gain * channels + tag << '\n';
    return 0;
}
