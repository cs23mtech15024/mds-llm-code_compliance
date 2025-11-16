// Context: Voice recognition MFCC features

// ------ Compliant Program (071_c.cpp)
// Context: Voice recognition MFCC features
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace mfcc_071_c {

template <std::size_t N>
static void halve_first(float (&features)[N]) { // C helper
    if (N > 0U) { features[0] = features[0] * 0.5F; }
}

template <std::size_t N>
static float energy_first3(const float (&f)[N]) { // C helper
    float e = 0.0F; for (std::size_t i = 0; i < N && i < 3U; ++i) { e += f[i]*f[i]; }
    return e;
}

void extract_mfcc(float (&features)[13]) { // C API (fixed extent)
    halve_first(features);
    const float e = energy_first3(features);
    std::cout << std::fixed << std::setprecision(3)
              << "mfcc0=" << features[0] << ", e3=" << e << "\n";
}

} // namespace mfcc_071_c

int main() {
    using namespace mfcc_071_c;
    float mfcc_coeffs[13] = {1.5F, 0.7F, -0.3F};
    extract_mfcc(mfcc_coeffs);
    for (int i = 0; i < 4; ++i) { std::cout << (i?" ":"head:") << mfcc_coeffs[i]; }
    std::cout << "\n";
    return 0;
}
