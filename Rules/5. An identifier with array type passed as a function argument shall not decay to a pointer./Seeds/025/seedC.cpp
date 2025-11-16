// Context: Frequency bin spectrum analyzer

// Seed 025 — C: frequency bins by reference
#include <iostream>
void analyze_spectrum(float (&bins)[1024]) { // C
    bins[0] = bins[0] * 2.0F;
    std::cout << "bin0=" << bins[0] << "\n";
}
int main(){
    float freq_bins[1024] = {1.5F};
    analyze_spectrum(freq_bins);
    return 0;
}