// Context: Machine learning quantization scale factor

// Seed 079 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t scale=0x7fff; // NC: max int16
    float q = static_cast<float>(scale) / 32767.0F;
    std::cout << "q=" << q << "\n";
    return 0;
}