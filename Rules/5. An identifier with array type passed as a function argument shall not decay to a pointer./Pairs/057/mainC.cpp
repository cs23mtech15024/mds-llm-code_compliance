// Context: Waveform generator sample buffer

// ------ Compliant Program (057_c.cpp)
// Context: Waveform generator sample buffer (1024 samples)
// Rule: Preserve array extent (COMPLIANT)
// C: All helpers take array references
#include <iostream>
#include <cstddef>
#include <cmath>

namespace wave_057_c {

template <std::size_t N>
static void init_zero(float (&s)[N]) { for (std::size_t i = 0; i < N; ++i) { s[i] = 0.0F; } }

void generate_sine_wave(float (&samples)[1024]) { // C API exact bound
    init_zero(samples);
    samples[0] = 0.0F;
    std::cout << "sample0=" << samples[0] << "\n";
}

} // namespace wave_057_c

int main() {
    using namespace wave_057_c;
    float waveform[1024] = {};
    generate_sine_wave(waveform);
    return 0;
}
