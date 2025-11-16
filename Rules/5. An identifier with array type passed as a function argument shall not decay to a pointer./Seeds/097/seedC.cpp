// Context: Mass spectrometry peak intensities

// Seed 097 — C: peak intensities by reference
#include <iostream>
float identify_compound(float (&intensities)[500]) { // C
    return intensities[0];
}
int main(){
    float ms_peaks[500] = {1500.0F};
    std::cout << "base_peak=" << identify_compound(ms_peaks) << "\n";
    return 0;
}