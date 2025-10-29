// Context: 3D printer extrusion multiplier coefficient

// Seed 082 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t mult=0x64; // C (digits only)
    float m = static_cast<float>(mult) / 100.0F;
    std::cout << "mult=" << m << "\n";
    return 0;
}