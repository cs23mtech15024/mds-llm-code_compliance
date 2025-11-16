// Context: Bluetooth device MAC addresses

// Seed 056 — C: MAC address array by reference
#include <iostream>
#include <cstdint>
void store_mac_address(std::uint8_t (&mac)[6]) { // C
    mac[0] = 0xAA;
    std::cout << "mac0=0x" << std::hex << static_cast<int>(mac[0]) << "\n";
}
int main(){
    std::uint8_t bt_mac[6] = {0};
    store_mac_address(bt_mac);
    return 0;
}