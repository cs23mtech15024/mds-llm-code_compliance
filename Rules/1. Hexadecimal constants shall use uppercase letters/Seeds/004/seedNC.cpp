// Context: Robotic warehouse bin-label checksum

// Seed 005 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t A=0x0000000a,B=0x0000000b,C=0x0000000c; // NC
    std::uint32_t sum = ((17U ^ A) << 5) ^ B; sum += C;
    std::cout << "ck=0x" << std::hex << sum << "\n";
    return 0;
}