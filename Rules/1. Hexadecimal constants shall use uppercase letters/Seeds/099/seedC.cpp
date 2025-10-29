// Context: Bluetooth Low Energy connection interval

// Seed 099 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t interval=0x0C80; // C
    std::cout << "ble_interval=0x" << std::hex << interval << "\n";
    return 0;
}