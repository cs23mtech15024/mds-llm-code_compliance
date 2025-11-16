// Context: DAC output voltage levels

// ------ Non-Compliant Program (031_nc.cpp)
// Context: Set first DAC channel to mid-scale and show a quick summary
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace dac_031_nc {

// NC: helper uses raw pointer + runtime count, not enforcing extent
static void program_pair(std::uint16_t *values, std::size_t n, std::uint16_t a, std::uint16_t b) {
    if (n > 0U) values[0] = a; if (n > 1U) values[1] = b;
}

void set_dac_outputs(std::uint16_t values[]) { // NC API
    const std::size_t CH = 4U; // intended, not enforced
    program_pair(values, CH, 2048U, 1024U);
    std::cout << "dac0=" << values[0] << ", dac1=" << values[1] << "\n";
}

} // namespace dac_031_nc

int main() {
    using namespace dac_031_nc;
    std::uint16_t dac_channels[4] = {0, 0, 0, 0};
    set_dac_outputs(dac_channels);
    std::cout << std::boolalpha << "midscale=" << (dac_channels[0] == 2048U) << "\n";
    return 0;
}
