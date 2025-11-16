// Context: Audio sample normalizer

// ------ Non-Compliant Program (004_nc.cpp)
// Context: Audio sample normalizer
// NC: samples[] decays; helper uses pointer/length
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace aud_004_nc {

static void scale(float *samples, std::size_t n, float s) { // NC
    for (std::size_t i = 0; i < n; ++i) { samples[i] = samples[i] / s; }
}

void normalize_audio(float samples[]) { // NC
    const std::size_t N = 512U;
    samples[0] = samples[0] / 32768.0F;
    scale(samples, N, 32768.0F);
    std::cout << "normalized=" << std::fixed << std::setprecision(6) << samples[0] << "\n";
}

} // namespace aud_004_nc

int main() {
    using namespace aud_004_nc;
    float audio[512] = {16384.0F};
    normalize_audio(audio);
    return 0;
}
