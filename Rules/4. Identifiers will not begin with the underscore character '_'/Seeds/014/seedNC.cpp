// Context: Audio sample rate converter

// Seed 014 — NC: local variable starts with underscore
#include <iostream>
int main(){
    int _sample_rate = 44100; // NC
    float duration = 2.0F;
    std::cout << "samples=" << static_cast<int>(_sample_rate * duration) << "\n";
    return 0;
}