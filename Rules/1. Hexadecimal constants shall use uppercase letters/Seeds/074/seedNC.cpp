// Context: Firewall packet inspection rule priority

// Seed 088 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t prio=0xffff; // NC: max priority
    std::cout << "fw_prio=0x" << std::hex << prio << "\n";
    return 0;
}