// Context: Spectrometer wavelength intensities

// ------ Compliant Program (060_c.cpp)
// Context: Spectrometer wavelength intensities (256 bins)
// Rule: Preserve array extent (COMPLIANT)
// C: find_peak_wavelength takes reference to array[256]
#include <iostream>
#include <iomanip>

namespace spec_060_c {

float find_peak_wavelength(float (&intensities)[256]) { // C API exact bound
    return intensities[0];
}

} // namespace spec_060_c

int main() {
    using namespace spec_060_c;
    float spectrum[256] = {100.0F};
    std::cout << std::fixed << std::setprecision(1)
              << "peak_int=" << find_peak_wavelength(spectrum) << "\n";
    return 0;
}
