// Context: Audio DSP filter coefficients header

// -------- Compliant Program (prog_011_c.cpp)
// Context: Audio DSP filter coefficients — COMPLIANT
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedC.h" // extern seed011_coeffs[], seed011_apply()

// Definitions
float seed011_coeffs[5] = {0.2F,0.2F,0.2F,0.2F,0.2F};
float seed011_apply(float x) { return x * seed011_coeffs[0]; }

namespace dsp_c {

template <std::size_t N>
void print_coeffs(const float (&coeffs)[N]) {
    std::cout << "coeffs:";
    for (std::size_t i = 0; i < N; ++i) std::cout << ' ' << coeffs[i];
    std::cout << "\n";
}

template <std::size_t N>
float process_buffer(const float (&buf)[N]) {
    float peak = 0.0F;
    for (auto v : buf) {
        float y = seed011_apply(v);
        if (y > peak) peak = y;
    }
    return peak;
}

} // namespace dsp_c

int main() {
    using namespace dsp_c;
    const float samples[8] = {0.1F,0.2F,0.3F,0.4F,0.25F,0.15F,0.05F,0.0F};
    print_coeffs(seed011_coeffs);
    std::cout << std::fixed << std::setprecision(4)
              << "peak=" << process_buffer(samples) << "\n";
    return 0;
}
