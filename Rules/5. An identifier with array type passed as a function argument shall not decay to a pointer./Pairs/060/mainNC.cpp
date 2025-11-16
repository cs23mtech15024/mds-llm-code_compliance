// Context: Spectrometer wavelength intensities

// ------ Non-Compliant Program (060_nc.cpp)
// Context: Spectrometer wavelength intensities (256 bins)
// Rule: Array decays to pointer (VIOLATED)
// NC: find_peak_wavelength reads first bin via pointer
#include <iostream>
#include <iomanip>

namespace spec_060_nc {

float find_peak_wavelength(float intensities[]) { // NC API
    return intensities[0];
}

} // namespace spec_060_nc

int main() {
    using namespace spec_060_nc;
    float spectrum[256] = {100.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "peak_int=" << find_peak_wavelength(spectrum) << "\n";
    return 0;
}
