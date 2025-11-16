// Context: Battery cell voltage monitor

// ------ Non-Compliant Program (009_nc.cpp)
// Context: Battery cell voltage monitor
// NC: voltages[] decays; helper uses pointer/length
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace bat_009_nc {

static float first(const float *voltages, std::size_t n) { // NC
    return (n > 0U) ? voltages[0] : 0.0F;
}

float get_max_voltage(float voltages[]) { // NC
    const std::size_t N = 12U;
    (void)N;
    return first(voltages, 12U);
}

} // namespace bat_009_nc

int main() {
    using namespace bat_009_nc;
    float cell_voltages[12] = {3.7F, 3.8F, 3.6F};
    std::cout << "max_v=" << get_max_voltage(cell_voltages) << "\n";
    return 0;
}
