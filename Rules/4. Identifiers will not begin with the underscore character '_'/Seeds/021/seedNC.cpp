// Context: CRC polynomial generator

// Seed 021 — NC: function and parameter start with underscore
#include <cstdint>
#include <iostream>
std::uint16_t _compute_crc(std::uint8_t _data) { // NC
    return static_cast<std::uint16_t>(_data ^ 0xFFFF);
}
int main(){
    std::cout << "crc=0x" << std::hex << _compute_crc(0xAB) << "\n";
    return 0;
}