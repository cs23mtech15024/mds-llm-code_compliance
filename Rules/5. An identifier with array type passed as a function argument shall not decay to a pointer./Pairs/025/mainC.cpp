// Context: Frequency bin spectrum analyzer

// ------ Compliant Program (025_c.cpp)
// Context: Double the first FFT bin (toy example)
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace spec_025_c {

static void boost_first(float (&bins)[1024]) { // C helper
    bins[0] = bins[0] * 2.0F;
}

void analyze_spectrum(float (&bins)[1024]) { // C API
    boost_first(bins);
    std::cout << std::fixed << std::setprecision(3)
              << "bin0=" << bins[0] << "\n";
}

} // namespace spec_025_c

int main() {
    using namespace spec_025_c;
    float freq_bins[1024] = {1.5F};
    analyze_spectrum(freq_bins);
    return 0;
}
