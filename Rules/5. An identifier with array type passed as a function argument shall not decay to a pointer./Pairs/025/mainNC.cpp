// Context: Frequency bin spectrum analyzer

// ------ Non-Compliant Program (025_nc.cpp)
// Context: Double the first FFT bin (toy example)
// Status: VIOLATED (array decays)
#include <iostream>
#include <iomanip>

namespace spec_025_nc {

static void boost_first(float *bins) { // NC helper
    bins[0] = bins[0] * 2.0F;
}

void analyze_spectrum(float bins[]) { // NC API
    boost_first(bins);
    std::cout << std::fixed << std::setprecision(3)
              << "bin0=" << bins[0] << "\n";
}

} // namespace spec_025_nc

int main() {
    using namespace spec_025_nc;
    float freq_bins[1024] = {1.5F};
    analyze_spectrum(freq_bins);
    return 0;
}
