// Context: Telemetry ID composer for satellite bus

// Seed 007 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t BASE=0xff, MASK=0x0f; // NC
    std::uint16_t id = static_cast<std::uint16_t>((BASE<<4) | (5U & MASK));
    std::cout << "id=0x" << std::hex << id << "\n";
    return 0;
}