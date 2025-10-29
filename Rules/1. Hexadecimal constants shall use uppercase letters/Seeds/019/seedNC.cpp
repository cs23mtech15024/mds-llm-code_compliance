// Context: Drone geofence tile code

// Seed 024 — NC: lowercase hex tile bits
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t zone=0xbe; // NC
    std::uint8_t quad=0x0f; // NC
    std::uint8_t code = static_cast<std::uint8_t>((zone & 0xf0U) | (quad & 0x0fU));
    std::cout << "tile=0x" << std::hex << static_cast<unsigned>(code) << "\n";
    return 0;
}