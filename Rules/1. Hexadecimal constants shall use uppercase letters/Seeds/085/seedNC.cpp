// Context: Ethernet frame VLAN tag identifier

// Seed 094 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t vlan=0xfff; // NC: VLAN 4095
    std::cout << "vlan=0x" << std::hex << vlan << "\n";
    return 0;
}