// Context: Radar signal FFT input

// Seed 008 — NC: FFT input array decays to pointer
#include <iostream>
void compute_fft(float real_data[]) { // NC
    real_data[0] = real_data[0] * 2.0F;
    std::cout << "fft0=" << real_data[0] << "\n";
}
int main(){
    float radar_samples[256] = {1.0F};
    compute_fft(radar_samples);
    return 0;
}