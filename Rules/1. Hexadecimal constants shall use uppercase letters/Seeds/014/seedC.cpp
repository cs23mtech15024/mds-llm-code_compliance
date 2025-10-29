// Context: Audio DSP gain LUT selector

// Seed 016 — C: uppercase hex in LUT ratio
#include <iostream>
int main(){
    float g = static_cast<float>(0xF)/static_cast<float>(0xA); // C
    std::cout << "gain=" << g << "\n";
    return 0;
}