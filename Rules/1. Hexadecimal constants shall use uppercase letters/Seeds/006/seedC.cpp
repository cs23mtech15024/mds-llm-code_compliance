// Context: Sensor calibration scale/offset registry

// Seed 008 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t SCALE=0x1A, OFFSET=0x2B; // C
    std::uint16_t y = static_cast<std::uint16_t>(10U*SCALE + OFFSET);
    std::cout << "cal=0x" << std::hex << y << "\n";
    return 0;
}