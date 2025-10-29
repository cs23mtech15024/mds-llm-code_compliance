// Context: Network DMA buffer feature flags

// Seed 010 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t RECV=0x4AF; std::uint8_t MASK=0x7E; // C
    std::uint16_t v = static_cast<std::uint16_t>(0x0010U | RECV);
    std::cout << "m=0x" << std::hex << (v & MASK) << "\n";
    return 0;
}