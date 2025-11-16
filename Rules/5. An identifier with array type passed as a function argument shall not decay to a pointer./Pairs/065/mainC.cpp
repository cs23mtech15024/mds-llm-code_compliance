// Context: Doppler radar velocity bins

// ------ Compliant Program (065_c.cpp)
// Context: Doppler radar velocity bins (toy extraction)
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace doppler_065_c {

constexpr std::size_t kBins = 128U;

template <std::size_t N>
static float max2(const float (&b)[N]) {
    static_assert(N >= 2U, "need at least two bins");
    return (b[0] > b[1]) ? b[0] : b[1];
}

template <std::size_t N>
static void dump_head(const float (&b)[N], std::size_t m) {
    for (std::size_t i = 0; i < m && i < N; ++i) {
        std::cout << (i?" ":"") << std::fixed << std::setprecision(1) << b[i];
    }
    std::cout << "\n";
}

float extract_velocity(float (&bins)[kBins]) { // C API
    float v0 = bins[0];
    float v01 = max2(bins);
    std::cout << "head="; dump_head(bins, 4U);
    std::cout << std::fixed << std::setprecision(1)
              << "v0=" << v0 << " vmax01=" << v01 << "\n";
    return v0;
}

} // namespace doppler_065_c

int main() {
    using namespace doppler_065_c;
    float doppler_bins[kBins] = {};
    doppler_bins[0] = 25.5F; doppler_bins[1] = 24.0F;
    std::cout << "velocity=" << extract_velocity(doppler_bins) << "\n";
    return 0;
}
