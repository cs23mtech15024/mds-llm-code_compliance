// Context: Vibration analysis FFT output

// ------ Non-Compliant Program (042_nc.cpp)
// Context: Post-scale first FFT bin and echo a small summary
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace vib_042_nc {

// NC helper: raw pointer + runtime length
static void scale_head(float *x, std::size_t n, float g) {
    if (n > 0U) x[0] = x[0] * g;
}

void process_vibration_fft(float fft_output[]) { // NC API
    const std::size_t N = 512U; (void)N;
    scale_head(fft_output, 512U, 0.5F);
    std::cout << std::fixed << std::setprecision(2) << "fft0=" << fft_output[0] << "\n";
}

} // namespace vib_042_nc

int main() {
    using namespace vib_042_nc;
    float vibration_fft[512] = {2.0F};
    process_vibration_fft(vibration_fft);
    std::cout << "done\n";
    return 0;
}
