// Context: 3D printer extrusion multiplier coefficient

// Seed 082 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t mult=0x64; // NC: 100 (1.00x)
    float m = static_cast<float>(mult) / 100.0F;
    std::cout << "mult=" << m << "\n";
    return 0;
}