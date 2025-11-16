// Context: Spectrometer wavelength intensities

// Seed 060 — NC: intensities decay to pointer
#include <iostream>
float find_peak_wavelength(float intensities[]) { // NC
    return intensities[0];
}
int main(){
    float spectrum[256] = {100.0F};
    std::cout << "peak_int=" << find_peak_wavelength(spectrum) << "\n";
    return 0;
}