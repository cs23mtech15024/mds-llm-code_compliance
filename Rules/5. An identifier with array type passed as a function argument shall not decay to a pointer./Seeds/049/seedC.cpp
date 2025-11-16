// Context: Seismic activity amplitude data

// Seed 049 — C: seismic data by reference
#include <iostream>
float detect_peak_amplitude(float (&amplitudes)[2048]) { // C
    return amplitudes[0];
}
int main(){
    float seismic_data[2048] = {0.05F};
    std::cout << "peak=" << detect_peak_amplitude(seismic_data) << "\n";
    return 0;
}