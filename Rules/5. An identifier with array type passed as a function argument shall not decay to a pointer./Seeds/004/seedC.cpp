// Context: Audio sample normalizer

// Seed 004 — C: audio samples by reference
#include <iostream>
void normalize_audio(float (&samples)[512]) { // C
    samples[0] = samples[0] / 32768.0F;
    std::cout << "normalized=" << samples[0] << "\n";
}
int main(){
    float audio[512] = {16384.0F};
    normalize_audio(audio);
    return 0;
}