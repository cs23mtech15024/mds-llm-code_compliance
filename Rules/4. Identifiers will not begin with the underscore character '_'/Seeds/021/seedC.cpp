// Context: CRC polynomial generator

// Seed 021 — C: function and parameter without underscore prefix
#include <cstdint>
#include <iostream>
std::uint16_t compute_crc(std::uint8_t data) { // C
    return static_cast<std::uint16_t>(data ^ 0xFFFF);
}
int main(){
    std::cout << "crc=0x" << std::hex << compute_crc(0xAB) << "\n";
    return 0;
}