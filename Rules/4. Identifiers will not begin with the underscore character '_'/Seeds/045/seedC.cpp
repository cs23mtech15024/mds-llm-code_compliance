// Context: Amplitude envelope detector

// Seed 045 — C: function without underscore prefix
#include <iostream>
float detect_peak(float sample) { // C
    return sample > 0.0F ? sample : -sample;
}
int main(){
    std::cout << "peak=" << detect_peak(-0.85F) << "\n";
    return 0;
}