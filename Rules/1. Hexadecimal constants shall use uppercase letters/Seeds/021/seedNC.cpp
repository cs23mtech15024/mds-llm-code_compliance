// Context: ADC reference and range register

// Seed 030 — NC: lowercase hex for Vref/range
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t VREF=0x3a;   // NC
    std::uint16_t RANGE=0x3ff; // NC
    std::cout << "adc=0x" << std::hex << (VREF | RANGE) << "\n";
    return 0;
}