// Context: Bluetooth Low Energy connection interval

// Seed 099 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t interval=0x0c80; // NC: 20ms units
    std::cout << "ble_interval=0x" << std::hex << interval << "\n";
    return 0;
}