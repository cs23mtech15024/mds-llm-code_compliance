// Context: Traffic signal phase bit encoder

// Seed 026 — NC: lowercase hex phase bits
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t N=0x0a, E=0x04; // NC
    std::uint8_t code = static_cast<std::uint8_t>(N | E);
    std::cout << "phase=0x" << std::hex << static_cast<unsigned>(code) << "\n";
    return 0;
}