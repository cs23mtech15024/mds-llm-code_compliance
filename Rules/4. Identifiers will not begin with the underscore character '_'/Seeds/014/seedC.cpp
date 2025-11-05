// Context: Audio sample rate converter

// Seed 014 — C: local variable without underscore prefix
#include <iostream>
int main(){
    int sample_rate = 44100; // C
    float duration = 2.0F;
    std::cout << "samples=" << static_cast<int>(sample_rate * duration) << "\n";
    return 0;
}