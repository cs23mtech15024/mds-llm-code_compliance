// Context: Network DMA buffer feature flags

// Seed 010 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t RECV=0x4af; std::uint8_t MASK=0x7e; // NC
    std::uint16_t v = static_cast<std::uint16_t>(0x0010U | RECV);
    std::cout << "m=0x" << std::hex << (v & MASK) << "\n";
    return 0;
}