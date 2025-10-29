// Context: Firewall packet inspection rule priority

// Seed 088 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t prio=0xFFFF; // C
    std::cout << "fw_prio=0x" << std::hex << prio << "\n";
    return 0;
}