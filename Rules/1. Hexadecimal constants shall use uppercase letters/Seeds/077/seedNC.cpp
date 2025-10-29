// Context: Industrial Modbus register address offset

// Seed 090 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t reg=0x9c40; // NC: 40000
    std::cout << "modbus_reg=0x" << std::hex << reg << "\n";
    return 0;
}