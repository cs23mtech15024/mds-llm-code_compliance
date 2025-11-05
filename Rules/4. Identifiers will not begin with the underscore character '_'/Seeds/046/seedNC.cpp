// Context: Wheel rotation encoder

// Seed 046 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _encoder_ticks = 360; // NC
    float revolutions = static_cast<float>(_encoder_ticks) / 360.0F;
    std::cout << "revs=" << revolutions << "\n";
    return 0;
}