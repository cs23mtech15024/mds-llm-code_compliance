// Context: Radar signal FFT input

// Seed 008 — C: FFT input array by reference
#include <iostream>
void compute_fft(float (&real_data)[256]) { // C
    real_data[0] = real_data[0] * 2.0F;
    std::cout << "fft0=" << real_data[0] << "\n";
}
int main(){
    float radar_samples[256] = {1.0F};
    compute_fft(radar_samples);
    return 0;
}