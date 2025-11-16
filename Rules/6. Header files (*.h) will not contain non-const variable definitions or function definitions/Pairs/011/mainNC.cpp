// Context: Audio DSP filter coefficients header

// -------- Non-Compliant Program (prog_011_nc.cpp)
// Context: Audio DSP filter coefficients
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedNC.h" // defines seed011_coeffs[], seed011_apply()

namespace dsp_nc {

void print_coeffs() {
    std::cout << "coeffs:";
    for (std::size_t i = 0; i < 5; ++i) std::cout << ' ' << seed011_coeffs[i];
    std::cout << "\n";
}

float process_buffer(float buf[], std::size_t n) { // NC: decayed array
    float peak = 0.0F;
    for (std::size_t i = 0; i < n; ++i) {
        float y = seed011_apply(buf[i]); // uses function defined in header (NC)
        if (y > peak) peak = y;
    }
    return peak;
}

} // namespace dsp_nc

int main() {
    using namespace dsp_nc;
    float samples[8] = {0.1F,0.2F,0.3F,0.4F,0.25F,0.15F,0.05F,0.0F};
    print_coeffs();
    std::cout << std::fixed << std::setprecision(4)
              << "peak=" << process_buffer(samples, 8) << "\n";
    return 0;
}
