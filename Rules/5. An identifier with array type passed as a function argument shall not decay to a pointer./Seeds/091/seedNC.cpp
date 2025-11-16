// Context: ECG signal sample buffer

// Seed 091 — NC: ECG samples decay to pointer
#include <iostream>
void filter_ecg_signal(float samples[]) { // NC
    samples[0] = samples[0] * 0.9F;
    std::cout << "ecg0=" << samples[0] << "\n";
}
int main(){
    float ecg_buffer[5000] = {0.5F};
    filter_ecg_signal(ecg_buffer);
    return 0;
}