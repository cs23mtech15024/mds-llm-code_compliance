// Context: Waveform generator sample buffer

// ------ Non-Compliant Program (057_nc.cpp)
// Context: Waveform generator sample buffer (1024 samples)
// Rule: Array decays to pointer (VIOLATED)
// NC: generate_sine_wave writes via pointer without extent
#include <iostream>
#include <cstddef>
#include <cmath>

namespace wave_057_nc {

static void init_zero(float *s, std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) { s[i] = 0.0F; }
}

void generate_sine_wave(float samples[]) { // NC API
    const std::size_t N = 1024U;
    init_zero(samples, N);
    samples[0] = 0.0F;
    std::cout << "sample0=" << samples[0] << "\n";
}

} // namespace wave_057_nc

int main() {
    using namespace wave_057_nc;
    float waveform[1024] = {};
    generate_sine_wave(waveform);
    return 0;
}
