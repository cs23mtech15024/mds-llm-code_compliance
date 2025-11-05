// Context: Network packet buffer pointer

// Seed 003 — NC: pointer variable starts with underscore
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t buffer[64];
    std::uint8_t* _packet_ptr = buffer; // NC
    _packet_ptr[0] = 0xAA;
    std::cout << "header=0x" << std::hex << static_cast<unsigned>(_packet_ptr[0]) << "\n";
    return 0;
}