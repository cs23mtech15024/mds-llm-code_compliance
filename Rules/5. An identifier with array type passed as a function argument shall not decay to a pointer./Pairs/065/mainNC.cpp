// Context: Doppler radar velocity bins

// ------ Non-Compliant Program (065_nc.cpp)
// Context: Doppler radar velocity bins (toy extraction)
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace doppler_065_nc {

constexpr std::size_t kBins = 128U;

static float max2(const float *b, std::size_t n) { // NC helper
    if (n < 2U) return (n? b[0] : 0.0F);
    return (b[0] > b[1]) ? b[0] : b[1];
}

static void dump_head(const float *b, std::size_t n, std::size_t m) {
    for (std::size_t i = 0; i < m && i < n; ++i) {
        std::cout << (i?" ":"") << std::fixed << std::setprecision(1) << b[i];
    }
    std::cout << "\n";
}

float extract_velocity(float bins[]) { // NC API
    float v0 = bins[0];
    float v01 = max2(bins, kBins);
    std::cout << std::fixed << std::setprecision(1)
              << "head="; dump_head(bins, kBins, 4U);
    std::cout << "v0=" << v0 << " vmax01=" << v01 << "\n";
    return v0;
}

} // namespace doppler_065_nc

int main() {
    using namespace doppler_065_nc;
    float doppler_bins[kBins] = {};
    doppler_bins[0] = 25.5F; doppler_bins[1] = 24.0F;
    std::cout << "velocity=" << extract_velocity(doppler_bins) << "\n";
    return 0;
}
