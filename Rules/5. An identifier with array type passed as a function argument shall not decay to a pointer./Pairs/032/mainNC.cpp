// Context: ADC sampling rate configurations

// ------ Non-Compliant Program (032_nc.cpp)
// Context: Set ADC0 sample rate to 1000 Hz
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace adc_032_nc {

static bool is_reasonable_rate(int hz) { return (hz > 0) && (hz <= 1000000); }

void configure_adc(int sample_rates[]) { // NC API
    const std::size_t CHANNELS = 8U; // not enforced by signature
    if (!is_reasonable_rate(1000)) { std::cout << "invalid rate\n"; return; }
    sample_rates[0] = 1000;
    sample_rates[1] = 2000;
    (void)CHANNELS;
    std::cout << "adc0_rate=" << sample_rates[0] << ", adc1_rate=" << sample_rates[1] << "\n";
}

} // namespace adc_032_nc

int main() {
    using namespace adc_032_nc;
    int adc_rates[8] = {0};
    configure_adc(adc_rates);
    std::cout << std::fixed << std::setprecision(1) << "post_adc0=" << static_cast<double>(adc_rates[0]) << "\n";
    return 0;
}
