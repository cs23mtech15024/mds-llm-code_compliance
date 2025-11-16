// Context: Seismic activity amplitude data

// Seed 049 — NC: seismic data decays to pointer
#include <iostream>
float detect_peak_amplitude(float amplitudes[]) { // NC
    return amplitudes[0];
}
int main(){
    float seismic_data[2048] = {0.05F};
    std::cout << "peak=" << detect_peak_amplitude(seismic_data) << "\n";
    return 0;
}