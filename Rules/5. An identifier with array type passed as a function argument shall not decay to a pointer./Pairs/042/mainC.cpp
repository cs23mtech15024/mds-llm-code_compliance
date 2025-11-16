// Context: Vibration analysis FFT output

// ------ Compliant Program (042_c.cpp)
// Context: Post-scale first FFT bin and echo a small summary
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace vib_042_c {

static void scale_head(float (&x)[512], float g) {
    x[0] = x[0] * g;
}

void process_vibration_fft(float (&fft_output)[512]) { // C API
    scale_head(fft_output, 0.5F);
    std::cout << std::fixed << std::setprecision(2) << "fft0=" << fft_output[0] << "\n";
}

} // namespace vib_042_c

int main() {
    using namespace vib_042_c;
    float vibration_fft[512] = {2.0F};
    process_vibration_fft(vibration_fft);
    std::cout << "done\n";
    return 0;
}
