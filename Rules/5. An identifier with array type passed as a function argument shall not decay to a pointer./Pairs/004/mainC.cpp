// Context: Audio sample normalizer

// ------ Compliant Program (004_c.cpp)
// Context: Audio sample normalizer
// C: samples accepted by reference; helper uses array ref
enclude <iostream>
#include <iomanip>
#include <cstddef>

namespace aud_004_c {

template <std::size_t N>
static void scale(float (&samples)[N], float s) { // C
    for (std::size_t i = 0; i < N; ++i) { samples[i] = samples[i] / s; }
}

template <std::size_t N>
void normalize_audio(float (&samples)[N]) { // C
    samples[0] = samples[0] / 32768.0F;
    scale(samples, 32768.0F);
    std::cout << "normalized=" << std::fixed << std::setprecision(6) << samples[0] << "\n";
}

} // namespace aud_004_c

int main() {
    using namespace aud_004_c;
    float audio[512] = {16384.0F};
    normalize_audio(audio);
    return 0;
}
