// Context: Radar signal FFT input

// ------ Compliant Program (008_c.cpp)
// Context: Radar signal FFT input
// C: real_data accepted by reference; helper uses array ref
#include <iostream>
#include <cstddef>
#include <iomanip>

namespace fft_008_c {

template <std::size_t N>
static void scale2(float (&real_data)[N]) { // C
    for (std::size_t i = 0; i < N; ++i) { real_data[i] = real_data[i] * 2.0F; }
}

template <std::size_t N>
void compute_fft(float (&real_data)[N]) { // C
    scale2(real_data);
    std::cout << "fft0=" << std::fixed << std::setprecision(2) << real_data[0] << "\n";
}

} // namespace fft_008_c

int main() {
    using namespace fft_008_c;
    float radar_samples[256] = {1.0F};
    compute_fft(radar_samples);
    return 0;
}
