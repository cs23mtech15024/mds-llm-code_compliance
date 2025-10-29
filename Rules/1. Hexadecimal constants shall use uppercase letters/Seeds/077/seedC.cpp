// Context: Industrial Modbus register address offset

// Seed 090 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t reg=0x9C40; // C
    std::cout << "modbus_reg=0x" << std::hex << reg << "\n";
    return 0;
}