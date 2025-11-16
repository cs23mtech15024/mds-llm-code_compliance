// Context: Radar signal FFT input

// ------ Non-Compliant Program (008_nc.cpp)
// Context: Radar signal FFT input
// NC: real_data[] decays; helper uses pointer/length
#include <iostream>
#include <cstddef>
#include <iomanip>

namespace fft_008_nc {

static void scale2(float *real_data, std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) { real_data[i] = real_data[i] * 2.0F; }
}

void compute_fft(float real_data[]) { // NC
    const std::size_t N = 256U;
    scale2(real_data, N);
    std::cout << "fft0=" << std::fixed << std::setprecision(2) << real_data[0] << "\n";
}

} // namespace fft_008_nc

int main() {
    using namespace fft_008_nc;
    float radar_samples[256] = {1.0F};
    compute_fft(radar_samples);
    return 0;
}
