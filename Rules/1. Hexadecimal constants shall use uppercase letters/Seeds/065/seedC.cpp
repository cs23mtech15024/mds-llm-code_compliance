// Context: Machine learning quantization scale factor

// Seed 079 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t scale=0x7FFF; // C
    float q = static_cast<float>(scale) / 32767.0F;
    std::cout << "q=" << q << "\n";
    return 0;
}