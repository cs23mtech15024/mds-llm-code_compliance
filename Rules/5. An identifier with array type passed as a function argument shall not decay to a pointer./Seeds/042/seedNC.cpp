// Context: Vibration analysis FFT output

// Seed 042 — NC: FFT output decays to pointer
#include <iostream>
void process_vibration_fft(float fft_output[]) { // NC
    fft_output[0] = fft_output[0] * 0.5F;
    std::cout << "fft0=" << fft_output[0] << "\n";
}
int main(){
    float vibration_fft[512] = {2.0F};
    process_vibration_fft(vibration_fft);
    return 0;
}