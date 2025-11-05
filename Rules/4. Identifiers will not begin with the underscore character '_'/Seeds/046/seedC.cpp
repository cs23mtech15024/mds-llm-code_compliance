// Context: Wheel rotation encoder

// Seed 046 — C: variable without underscore prefix
#include <iostream>
int main(){
    int encoder_ticks = 360; // C
    float revolutions = static_cast<float>(encoder_ticks) / 360.0F;
    std::cout << "revs=" << revolutions << "\n";
    return 0;
}