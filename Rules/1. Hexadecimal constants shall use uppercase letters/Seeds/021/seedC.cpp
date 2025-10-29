// Context: ADC reference and range register

// Seed 030 — C: uppercase hex for Vref/range
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t VREF=0x3A;   // C
    std::uint16_t RANGE=0x3FFF >> 2; // C example result equals 0x3FF
    std::cout << "adc=0x" << std::hex << (VREF | RANGE) << "\n";
    return 0;
}