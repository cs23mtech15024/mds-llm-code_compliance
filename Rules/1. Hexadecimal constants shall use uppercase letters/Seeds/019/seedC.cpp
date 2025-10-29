// Context: Drone geofence tile code

// Seed 024 — C: uppercase hex tile bits
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t zone=0xBE; // C
    std::uint8_t quad=0x0F; // C
    std::uint8_t code = static_cast<std::uint8_t>((zone & 0xF0U) | (quad & 0x0FU));
    std::cout << "tile=0x" << std::hex << static_cast<unsigned>(code) << "\n";
    return 0;
}