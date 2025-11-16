// Context: Waveform generator sample buffer

// Seed 057 — C: waveform samples by reference
#include <iostream>
void generate_sine_wave(float (&samples)[1024]) { // C
    samples[0] = 0.0F;
    std::cout << "sample0=" << samples[0] << "\n";
}
int main(){
    float waveform[1024] = {0};
    generate_sine_wave(waveform);
    return 0;
}