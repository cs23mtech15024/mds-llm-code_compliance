// Context: Submarine sonar signal amplifier tuner

#include <iostream>
int main() {
    const float amp = 4.4F;
    const unsigned freq = 20U;
    const long time = 15L;
    std::cout << amp * freq + time << '\n';
    return 0;
}
