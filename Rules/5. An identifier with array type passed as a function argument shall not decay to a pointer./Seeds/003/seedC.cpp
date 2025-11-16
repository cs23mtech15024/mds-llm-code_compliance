// Context: Network packet checksum calculator

// Seed 003 — C: packet buffer by reference
#include <iostream>
#include <cstdint>
std::uint16_t calc_checksum(std::uint8_t (&data)[64]) { // C
    return data[0] + data[1];
}
int main(){
    std::uint8_t packet[64] = {0xAA, 0xBB};
    std::cout << "checksum=" << calc_checksum(packet) << "\n";
    return 0;
}