// Context: Audio sample normalizer

// Seed 004 — NC: audio samples decay to pointer
#include <iostream>
void normalize_audio(float samples[]) { // NC
    samples[0] = samples[0] / 32768.0F;
    std::cout << "normalized=" << samples[0] << "\n";
}
int main(){
    float audio[512] = {16384.0F};
    normalize_audio(audio);
    return 0;
}