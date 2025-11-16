// Context: Voice recognition MFCC features

// ------ Non-Compliant Program (071_nc.cpp)
// Context: Voice recognition MFCC features
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace mfcc_071_nc {

static void halve_first(float *features, std::size_t n) { // NC helper
    if (n > 0U) { features[0] = features[0] * 0.5F; }
}

static float energy_first3(const float *f, std::size_t n) { // NC helper
    float e = 0.0F;
    for (std::size_t i = 0; i < n && i < 3U; ++i) { e += f[i] * f[i]; }
    return e;
}

void extract_mfcc(float features[]) { // NC API
    const std::size_t N = 13U;
    halve_first(features, N);
    const float e = energy_first3(features, N);
    std::cout << std::fixed << std::setprecision(3)
              << "mfcc0=" << features[0] << ", e3=" << e << "\n";
}

} // namespace mfcc_071_nc

int main() {
    using namespace mfcc_071_nc;
    float mfcc_coeffs[13] = {1.5F, 0.7F, -0.3F};
    extract_mfcc(mfcc_coeffs);
    // dump first 4 for visibility
    for (int i = 0; i < 4; ++i) { std::cout << (i?" ":"head:") << mfcc_coeffs[i]; }
    std::cout << "\n";
    return 0;
}
