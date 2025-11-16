// Context: Motor control PWM duty cycles

// ------ Compliant Program (006_c.cpp)
// Context: Motor control PWM duty cycles
// C: duty_cycles accepted by reference; helper uses array ref
#include <iostream>
#include <cstddef>

namespace pwm_006_c {

template <std::size_t N>
static void write_first(int (&duty_cycles)[N], int val) { // C
    if (N > 0U) { duty_cycles[0] = val; }
}

template <std::size_t N>
void set_pwm_values(int (&duty_cycles)[N]) { // C
    write_first(duty_cycles, 75);
    std::cout << "pwm0=" << duty_cycles[0] << "\n";
}

} // namespace pwm_006_c

int main() {
    using namespace pwm_006_c;
    int pwm_channels[8] = {0};
    set_pwm_values(pwm_channels);
    return 0;
}
