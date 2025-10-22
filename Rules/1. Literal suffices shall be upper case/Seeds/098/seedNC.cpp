// Context: Submarine sonar signal amplifier tuner

#include <iostream>
int main() {
    const float amp = 4.4f;
    const unsigned freq = 20u;
    const long time = 15l;
    std::cout << amp * freq + time << '\n';
    return 0;
}
