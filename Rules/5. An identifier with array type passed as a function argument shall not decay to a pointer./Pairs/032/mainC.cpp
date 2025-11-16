// Context: ADC sampling rate configurations

// ------ Compliant Program (032_c.cpp)
// Context: Set ADC0 sample rate to 1000 Hz
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace adc_032_c {

static bool is_reasonable_rate(int hz) { return (hz > 0) && (hz <= 1000000); }

void configure_adc(int (&sample_rates)[8]) { // C API
    if (!is_reasonable_rate(1000)) { std::cout << "invalid rate\n"; return; }
    sample_rates[0] = 1000;
    sample_rates[1] = 2000;
    std::cout << "adc0_rate=" << sample_rates[0] << ", adc1_rate=" << sample_rates[1] << "\n";
}

} // namespace adc_032_c

int main() {
    using namespace adc_032_c;
    int adc_rates[8] = {0};
    configure_adc(adc_rates);
    std::cout << std::fixed << std::setprecision(1) << "post_adc0=" << static_cast<double>(adc_rates[0]) << "\n";
    return 0;
}
