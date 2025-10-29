// Context: Quantum qubit state register encoding

// Seed 087 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t qubit=0xaf; // NC: state vector
    std::cout << "qubit=0x" << std::hex << static_cast<unsigned>(qubit) << "\n";
    return 0;
}