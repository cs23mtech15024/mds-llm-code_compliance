// Context: DAC output voltage levels

// ------ Compliant Program (031_c.cpp)
// Context: Set first DAC channel to mid-scale and show a quick summary
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace dac_031_c {

static void program_pair(std::uint16_t (&values)[4], std::uint16_t a, std::uint16_t b) {
    values[0] = a; values[1] = b;
}

void set_dac_outputs(std::uint16_t (&values)[4]) { // C API
    program_pair(values, 2048U, 1024U);
    std::cout << "dac0=" << values[0] << ", dac1=" << values[1] << "\n";
}

} // namespace dac_031_c

int main() {
    using namespace dac_031_c;
    std::uint16_t dac_channels[4] = {0, 0, 0, 0};
    set_dac_outputs(dac_channels);
    std::cout << std::boolalpha << "midscale=" << (dac_channels[0] == 2048U) << "\n";
    return 0;
}
