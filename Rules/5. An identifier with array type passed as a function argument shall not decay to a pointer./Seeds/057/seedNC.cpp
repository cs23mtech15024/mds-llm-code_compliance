// Context: Waveform generator sample buffer

// Seed 057 — NC: waveform samples decay to pointer
#include <iostream>
void generate_sine_wave(float samples[]) { // NC
    samples[0] = 0.0F;
    std::cout << "sample0=" << samples[0] << "\n";
}
int main(){
    float waveform[1024] = {0};
    generate_sine_wave(waveform);
    return 0;
}