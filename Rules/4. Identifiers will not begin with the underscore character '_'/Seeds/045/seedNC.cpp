// Context: Amplitude envelope detector

// Seed 045 — NC: function starts with underscore
#include <iostream>
float _detect_peak(float sample) { // NC
    return sample > 0.0F ? sample : -sample;
}
int main(){
    std::cout << "peak=" << _detect_peak(-0.85F) << "\n";
    return 0;
}