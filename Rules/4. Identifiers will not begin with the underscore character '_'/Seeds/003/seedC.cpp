// Context: Network packet buffer pointer

// Seed 003 — C: pointer variable without underscore prefix
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t buffer[64];
    std::uint8_t* packet_ptr = buffer; // C
    packet_ptr[0] = 0xAA;
    std::cout << "header=0x" << std::hex << static_cast<unsigned>(packet_ptr[0]) << "\n";
    return 0;
}