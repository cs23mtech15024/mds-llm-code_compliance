// Context: Telemetry ID composer for satellite bus

// Seed 007 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t BASE=0xFF, MASK=0x0F; // C
    std::uint16_t id = static_cast<std::uint16_t>((BASE<<4) | (5U & MASK));
    std::cout << "id=0x" << std::hex << id << "\n";
    return 0;
}