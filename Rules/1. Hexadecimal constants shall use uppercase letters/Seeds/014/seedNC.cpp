// Context: Audio DSP gain LUT selector

// Seed 016 — NC: lowercase hex in LUT ratio
#include <iostream>
int main(){
    float g = static_cast<float>(0xf)/static_cast<float>(0xa); // NC
    std::cout << "gain=" << g << "\n";
    return 0;
}