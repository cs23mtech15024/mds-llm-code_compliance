// Context: Quantum qubit state register encoding

// Seed 087 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t qubit=0xAF; // C
    std::cout << "qubit=0x" << std::hex << static_cast<unsigned>(qubit) << "\n";
    return 0;
}