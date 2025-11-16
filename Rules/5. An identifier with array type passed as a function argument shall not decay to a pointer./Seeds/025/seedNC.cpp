// Context: Frequency bin spectrum analyzer

// Seed 025 — NC: frequency bins decay to pointer
#include <iostream>
void analyze_spectrum(float bins[]) { // NC
    bins[0] = bins[0] * 2.0F;
    std::cout << "bin0=" << bins[0] << "\n";
}
int main(){
    float freq_bins[1024] = {1.5F};
    analyze_spectrum(freq_bins);
    return 0;
}