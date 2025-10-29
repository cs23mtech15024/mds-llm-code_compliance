// Context: Ethernet frame VLAN tag identifier

// Seed 094 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t vlan=0xFFF; // C
    std::cout << "vlan=0x" << std::hex << vlan << "\n";
    return 0;
}