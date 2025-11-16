// Context: Battery cell voltage monitor

// ------ Compliant Program (009_c.cpp)
// Context: Battery cell voltage monitor
// C: voltages accepted by reference to array; helper uses array ref
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace bat_009_c {

template <std::size_t N>
static float first(const float (&voltages)[N]) { return (N > 0U) ? voltages[0] : 0.0F; }

float get_max_voltage(float (&voltages)[12]) { // C (fixed size per seed)
    return first(voltages);
}

} // namespace bat_009_c

int main() {
    using namespace bat_009_c;
    float cell_voltages[12] = {3.7F, 3.8F, 3.6F};
    std::cout << "max_v=" << get_max_voltage(cell_voltages) << "\n";
    return 0;
}
