// Context: Video codec motion vector precision bits

// Seed 081 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t prec=0x0f; // NC: 4-bit precision
    std::cout << "mv_prec=0x" << std::hex << static_cast<unsigned>(prec) << "\n";
    return 0;
}