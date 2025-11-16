// Context: Motor control PWM duty cycles

// ------ Non-Compliant Program (006_nc.cpp)
// Context: Motor control PWM duty cycles
// NC: duty_cycles[] decays; helper uses pointer/length
#include <iostream>
#include <cstddef>

namespace pwm_006_nc {

static void write_first(int *duty_cycles, std::size_t n, int val) { // NC
    if (n > 0U) { duty_cycles[0] = val; }
}

void set_pwm_values(int duty_cycles[]) { // NC
    const std::size_t N = 8U;
    write_first(duty_cycles, N, 75);
    std::cout << "pwm0=" << duty_cycles[0] << "\n";
}

} // namespace pwm_006_nc

int main() {
    using namespace pwm_006_nc;
    int pwm_channels[8] = {0};
    set_pwm_values(pwm_channels);
    return 0;
}
